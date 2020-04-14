/*
    Problem: http://poj.org/problem?id=2374
    DP + SGT optimize
    Correct DP equation:
        SET l[0] = minimal r[0] = maximal (original point)
        dp[i][0] = min(dp[j][0]+(l[i]-l[j]), dp[j][1]+(r[j]-l[i]))     l[j] <= l[i] <= r[j] (j != 0) // so, add abs to equation
        dp[i][1] = min(dp[k][1]+(r[k]-r[i]), dp[k][0]+(r[i]-l[k]))     l[k] <= r[i] <= r[k] (j != 0) // so, add abs to equation
    Wrong DP equation:
        dp[i][] = min(dp[i-1][], ...)
    Reference: https://www.acwing.com/solution/acwing/content/8857/
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

const int N = 5e4+10;
const int OFFSET = 1e5+10;
int n, s;
int start[N], last[N];
int dp[N][2];
int id[OFFSET<<3], inv[OFFSET<<3];

void build(int o, int l, int r) {  
    inv[o] = 0;
    if (l == r) {
        id[o] = 0;
        return;
    }
    int m = (l+r)>>1;
    build(o<<1, l, m); build(o<<1|1, m+1, r);
    id[o] = 0;
}

void PushDown(int o) {
    //由于用法，懒惰标记只可能向下遍历，并且是在下一次更新或者查询操作中
    if (inv[o]) {
        // 更新的是下一层的区间
        id[o<<1] = inv[o];//区间修改
        id[o<<1|1] = inv[o];//区间修改
        inv[o<<1] = inv[o<<1|1] = inv[o];
        inv[o] = 0;//消除标记
    }
}

void modify(int o, int l, int r, int ql, int qr, int val) {
    if ((ql<=l) && (qr>=r)) {
        id[o] = val;
        inv[o] = val;
        return;
    }
    int m = (l+r)>>1;
    PushDown(o);////检查是否有之前遍历的懒惰标记
    if (ql <= m) modify(o<<1, l, m, ql, qr, val);
    if (qr > m) modify(o<<1|1, m+1, r, ql, qr, val);
}

int query(int o, int l, int r, int q) {
    if (l == r) {
        return id[o];
    }
    int m = (l+r)>>1;
    PushDown(o);
    int ans = 0;
    if (q <= m) ans = query(o<<1, l, m, q);
    if (q > m) ans = query(o<<1|1, m+1, r, q);
    return ans;
}

int main() {
    scanf("%d%d", &n, &s); s += OFFSET;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", start+i, last+i);
        start[i] += OFFSET;
        last[i] += OFFSET;
    }
    start[0] = OFFSET, last[0] = OFFSET;
    dp[0][0] = 0, dp[0][1] = 0;
    build(1, 0, OFFSET<<1);
    for (int i = 1; i <= n; ++i) {
        // Query nearest fence id
        int j = query(1, 0, OFFSET<<1, start[i]);
        dp[i][0] = min(dp[j][0]+abs(start[i]-start[j]), dp[j][1]+abs(start[i]-last[j]));
        // Query nearest fence id
        int k = query(1, 0, OFFSET<<1, last[i]);
        dp[i][1] = min(dp[k][0]+abs(last[i]-start[k]), dp[k][1]+abs(last[i]-last[k]));
        // cout << j << " " << k << endl;
        modify(1, 0, OFFSET<<1, start[i], last[i], i);
    }
    cout << min(dp[n][0]+abs(start[n]-s), dp[n][1]+abs(last[n]-s)) << endl;
	return 0;
}
