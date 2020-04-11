// https://www.acwing.com/problem/content/246/
// 维护区间连续最大值
// 通过维护这几个值来做到： 区间总和，区间前缀最大值，区间后缀最大值，区间连续最大和
/*
    sum[o] = sum[o<<1]+sum[o<<1|1]; 
    lm[o] = max(lm[o<<1], sum[o<<1]+lm[o<<1|1]); // 区间前缀最大值 = max(左子区间前缀最大值， 左子区间总和+右子区间前缀最大值)
    rm[o] = max(rm[o<<1|1], sum[o<<1|1]+rm[o<<1]); // 同理
    mxval[o] = max(max(mxval[o<<1], mxval[o<<1|1]), rm[o<<1]+lm[o<<1|1]); // 区间连续最大值 = max(max(左子区间最大值，右子区间最大值), 中间连续和)
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <deque>

#define ll long long
#define ull unsigned long long

using namespace std;

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int PI = acos(-1.0);

const int N = 5e5+5;

int n, m;
int val[N];
int sum[N<<2], lm[N<<2], rm[N<<2], mxval[N<<2];

void build (int o, int l, int r) {
    if (l == r) {
        sum[o] = val[l];
        lm[o] = val[l];
        rm[o] = val[l];
        mxval[o] = val[l];
        return;
    }
    int m = (l+r) >> 1;
    build(o<<1, l, m);
    build(o<<1|1, m+1, r);
    sum[o] = sum[o<<1]+sum[o<<1|1];
    lm[o] = max(lm[o<<1], sum[o<<1]+lm[o<<1|1]);
    rm[o] = max(rm[o<<1|1], sum[o<<1|1]+rm[o<<1]);
    mxval[o] = max(max(mxval[o<<1], mxval[o<<1|1]), rm[o<<1]+lm[o<<1|1]);
}

void update(int o, int l, int r, int idx, int goal) {
    if (l == r) {
        val[l] = goal;
        sum[o] = val[l];
        lm[o] = val[l];
        rm[o] = val[l];
        mxval[o] = val[l];
        return;
    }
    int m = (l+r) >> 1;
    if (idx > m)
        update(o<<1|1, m+1, r, idx, goal);
    else
        update(o<<1, l, m, idx, goal);
    sum[o] = sum[o<<1]+sum[o<<1|1];
    lm[o] = max(lm[o<<1], sum[o<<1]+lm[o<<1|1]);
    rm[o] = max(rm[o<<1|1], sum[o<<1|1]+rm[o<<1]);
    mxval[o] = max(max(mxval[o<<1], mxval[o<<1|1]), rm[o<<1]+lm[o<<1|1]);
}

void query (int o, int l, int r, int ql, int qr, int& pre, int& post, int& s, int& mx) {
    int m = (l+r) >> 1;
    if (ql <= l && r <= qr) {
        pre = lm[o];
        post = rm[o];
        s = sum[o];
        mx = mxval[o];
        return;
    }
    int r_pre = 0, r_post = 0, r_s = 0, r_mx = 0;
    int l_pre = 0, l_post = 0, l_s = 0, l_mx = 0;
    bool l_flag = 0, r_flag = 0;
    if (qr > m) {
        query (o<<1|1, m+1, r, ql, qr, r_pre, r_post, r_s, r_mx);
        l_flag = 1;
        pre = r_pre, post = r_post, mx = r_mx, s = r_s, mx = r_mx;
    }
    if (ql <= m) {
        query (o<<1, l, m, ql, qr, l_pre, l_post, l_s, l_mx);
        r_flag = 1;
        pre = l_pre, post = l_post, mx = l_mx, s = l_s, mx = l_mx;
    }
    if (r_flag && l_flag) {
        pre = max(l_pre, l_s+r_pre);
        post = max(r_post, r_s+l_post);
        s = r_s + l_s;
        mx = max(max(r_mx, l_mx), l_post+r_pre);
    }
}

int main() {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", val+i);
    // build tree
    build(1, 0, n-1);
    int o, x, y;
    while (m--) {
        scanf("%d%d%d", &o, &x, &y);
        if (o == 1) { // Query
            if (x > y) swap(x, y);
            int pre = 0, post = 0, s = 0, mx = 0;
            query(1, 0, n-1, x-1, y-1, pre, post, s, mx);
            printf("%d\n", mx);
        } else { // Update
            update(1, 0, n-1, x-1, y);
        }
    }
	return 0;
}
