// https://www.acwing.com/problem/content/246/
/*
    Replace to Long Long type if necessary
    gcd(a, b, c, d) = gcd(a, b-a, c-b, d-c)
    线段树 维护差分信息
    树状数组 维护增减信息
    gcd(a[i...j]) = gcd(a[i], g[差分])
    即可化成点修改！

    Reference:
    https://www.acwing.com/solution/acwing/content/1047/
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
int a[N], b[N];
ll g[N<<2], c[N<<2];


int gcd(int x, int y) {
    return y==0 ? x:gcd(y, x%y);
}

void build(int o, int l, int r) {  
    if (l == r) {
        g[o] = b[l];
        return;
    }
    int m = (l+r)>>1;
    build(o<<1, l, m); build(o<<1|1, m+1, r);
    g[o] = gcd(g[o<<1], g[o<<1|1]);
}

void add(int q, int o, int c, int l, int r) { // 点修改
    if (l == r) {
        g[o] += c;
        return;
    }
    int m = (l+r)>>1;
    if (q <= m) add(q, o<<1, c, l, m);
    else add(q, o<<1|1, c, m+1, r);
    g[o] = gcd(g[o<<1], g[o<<1|1]);
}

int query(int o, int l, int r, int ql, int qr) { // 区间查找
    if ((ql<=l) && (qr>=r))
        return g[o];
    int m = (l+r)>>1;
    int l_ans = 0, r_ans = 0; // if l_ans = 0, gcd(x, 0) = x
    if (ql <= m) l_ans = query(o<<1, l, m, ql, qr);
    if (qr > m) r_ans = query(o<<1|1, m+1, r, ql, qr);
    return abs(gcd(l_ans, r_ans)); // abs is important!
}

int lowbit (int x) {
    return x&(-x);
}

void change (int x, int d) { // d for delta
    while (x <= n) {
        c[x] += d;
        x += lowbit(x);
    }
}

int sum(int x) {
    int res = 0;
    while (x > 0) {
        res += c[x];
        x -= lowbit(x);//x=x&(x-1);
    }
    return res;
}

int main() {
    memset(c, 0, sizeof(c));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        b[i] = a[i]-a[i-1];
    }
    // build tree
    build(1, 1, n);
    int x, y, d;
    char o[3];
    while (m--) {
        scanf("%s", o);
        if (o[0] == 'Q') { // Query
            scanf("%d%d", &x, &y);
            int first = a[x] + sum(x);
            int rest = query(1, 1, n, x+1, y);
            printf("%d\n", gcd(first, rest));
        } else { // Update
            scanf("%d%d%d", &x, &y, &d);
            add(x, 1, d, 1, n); // 差分维护
            if (y < n)
                add(y+1, 1, -d, 1, n); // 差分维护
            change(x, d); // 数值维护，也可用区间修改的线段树
            change(y+1, -d);
        }
    }
	return 0;
}

