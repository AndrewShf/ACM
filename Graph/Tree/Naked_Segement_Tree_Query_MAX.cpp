/*
Segment Tree
最需要注意的是：范围别写错了。query的范围最容易写错。
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
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include<sstream>

#define ll long long
#define ull unsigned long long
#define local

using namespace std;

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const int PI = acos(-1.0);
const int N = 3e4+10;
const int M = 5010;

int n, m;
int v[N];
int mx[N*4];

void build(int o, int l, int r) {
    mx[o] = 0;
    if (l == r) {
        mx[o] = v[l];
        return;
    }
    int mid = (l+r)/2;
    build(o*2, l, mid);
    build(o*2+1, mid+1, r);
    mx[o] = max(mx[o*2], mx[o*2+1]);
}

void update(int num, int val, int l, int r, int o) {
    int mid = (l+r) / 2;
    if (l == r) {
        mx[o] = val;
        return;
    }
    if (num <= mid)
        update(num, val, l, mid, o*2);
    else
        update(num, val, mid+1, r, o*2+1);
    mx[o] = max(mx[o*2], mx[o*2+1]);
}

int query(int ql, int qr, int l, int r, int o) {
    int ans = -1;
    if (r < ql || l > qr) {
        return 0;
    } else if (r <= qr && l >= ql) {
        return mx[o];
    } else{
        int mid = (l+r)/2;
        ans = max(query(ql, qr, l, mid, 2*o), query(ql, qr, mid+1, r, 1+2*o));
    }
    return ans;
}

int main() {
	#ifdef local
		if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
	#endif

    while(scanf("%d%d", &n, &m) != -1) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", v+i);
        }
        char ch[2];
        int l, r;
        build(1, 1, n);
        while(m--) {
            scanf("%s%d%d", &ch, &l, &r);
            cout << ch << " " << l << " " << r << endl;
            if (l > r && ch[0]=='Q') {
                int tmp = r;
                r = l;
                l = tmp;
            }
            if (ch[0] == 'Q') {
                int ans = query(l, r, 1, n, 1);
                // printf("%d\n", ans);
            } else {
                update(l, r, 1, n, 1);
            }
        }
    }
	#ifdef local
	fclose(stdin);
	#endif
	return 0;
}
