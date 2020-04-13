/* https://www.acwing.com/problem/content/263/ */
/*
    lazy mark + segment tree
    prefix + suffix
    1. How to use LAZY MARK!!! use it in the right way
    2. bound control !
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
const int M = 5e4+10;
int n, m;

int sum[N<<2], lsum[N<<2], rsum[N<<2], inv[N<<2];

void build (int o, int l, int r) {
    inv[o] = 0;
    if (l == r) {
        sum[o] = 1;
        lsum[o] = 1;
        rsum[o] = 1;
        return;
    }
    int m = (l+r) >> 1;
    build(o<<1, l, m);
    build(o<<1|1, m+1, r);
    sum[o] = max(max(sum[o<<1], sum[o<<1|1]), rsum[o<<1]+lsum[o<<1|1]); // maximal 0 zone in o 
    lsum[o] = lsum[o<<1], rsum[o] = rsum[o<<1|1];
    if (lsum[o<<1] == m-l+1) lsum[o] = lsum[o<<1]+lsum[o<<1|1];
    if (rsum[o<<1|1] == r-m) rsum[o] = rsum[o<<1|1]+rsum[o<<1];
}

void pushdown(int o, int l, int r) {
    if (inv[o] == -1) { // not add rooms yet
        int m = (l+r)>>1;
        sum[o<<1] = m-l+1; lsum[o<<1] = m-l+1; rsum[o<<1] = m-l+1; // calculate sons
        sum[o<<1|1] = r-m; lsum[o<<1|1] = r-m; rsum[o<<1|1] = r-m;
        inv[o] = 0; // clear this one
        inv[o<<1|1] = -1; // add to the sons
        inv[o<<1] = -1;
    } else if (inv[o] > 0) { // not use rooms yet
        sum[o<<1] = 0; lsum[o<<1] = 0; rsum[o<<1] = 0;
        sum[o<<1|1] = 0; lsum[o<<1|1] = 0; rsum[o<<1|1] = 0;
        inv[o] = 0;
        inv[o<<1|1] = 1;
        inv[o<<1] = 1;
    }
}

void addRooms(int o, int l, int r, int ql, int qr) {
    int m = (l+r) >> 1;
    if (ql<=l && qr>=r) {
        sum[o] = r-l+1;
        lsum[o] = r-l+1;
        rsum[o] = r-l+1;
        inv[o] = -1; // add to this one == sons need to be calculated
        return;
    }
    pushdown(o, l, r);
    if (ql <= m)
        addRooms(o<<1, l, m, ql, qr);
    if (qr > m)
        addRooms(o<<1|1, m+1, r, ql, qr);
    sum[o] = max(max(sum[o<<1], sum[o<<1|1]), rsum[o<<1]+lsum[o<<1|1]);
    lsum[o] = lsum[o<<1], rsum[o] = rsum[o<<1|1];
    if (lsum[o<<1] == m-l+1) lsum[o] = lsum[o<<1]+lsum[o<<1|1]; // recalculate left sum
    if (rsum[o<<1|1] == r-m) rsum[o] = rsum[o<<1|1]+rsum[o<<1]; // 
}

void useRooms(int o,int l, int r, int ql, int qr) {
    if (ql<=l && qr>=r) {
        sum[o] = 0;
        lsum[o] = 0;
        rsum[o] = 0;
        inv[o] = 1;
        return;
    }
    int m = (l+r)>>1;
    pushdown(o, l, r);
    if (ql <= m) useRooms(o<<1, l, m, ql, qr);
    if (qr > m) useRooms(o<<1|1, m+1, r, ql, qr);
    sum[o] = max(max(sum[o<<1], sum[o<<1|1]), rsum[o<<1]+lsum[o<<1|1]);
    lsum[o] = lsum[o<<1], rsum[o] = rsum[o<<1|1];
    if (lsum[o<<1] == m-l+1) lsum[o] = lsum[o<<1]+lsum[o<<1|1];
    if (rsum[o<<1|1] == r-m) rsum[o] = rsum[o<<1|1]+rsum[o<<1];
}

int query(int o, int l, int r, int num) {
    if (num > sum[o]) {
        return -1;
    }
    int m = (l+r)>>1;
    pushdown(o, l, r);
    if (num <= lsum[o]) {
        return l;
    } else if (num <= sum[o<<1]){
        return query(o<<1, l, m, num);
    } else if (num <= (rsum[o<<1]+lsum[o<<1|1])){
        // cout << "rsum " << rsum[o<<1] << endl;
        return m-rsum[o<<1]+1;
    } else {
        return query(o<<1|1, m+1, r, num);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int x, y, z = 0;
    build(1, 0, n-1);
    while (m--) {
        scanf("%d %d", &x, &y);
        if (x == 2) { // change
            scanf(" %d", &z);
            addRooms(1, 0, n-1, y-1, y+z-2);
        } else { // Query
            int tmp = query(1, 0, n-1, y);
            if (tmp != -1)
                useRooms(1, 0, n-1, tmp, y+tmp-1);
            printf("%d\n", tmp+1);
        }
        // cout << x << " " << y << " " << z << endl;
    }
	return 0;
}
