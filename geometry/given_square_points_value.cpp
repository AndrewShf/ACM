/*
https://www.acwing.com/problem/content/250/
Line sweep + Segment tree ==> value in the square
Reference: https://oi-wiki.org/geometry/scanning/
Maintain the H-sized edge's maximal weight information by using segment tree

0. make the point to square!!!
1. bound control w-1; h-1
2. Edge sort: calculate positive edge first when x is the same (to seek the optimal value)

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

const int N = 3e4+5;

int n, w, h;
struct Tree {
    double l, r;
    double sum;
    int inv;
} tree[N<<3];

struct Node {
    int flag;
    double x, y1, y2;
} node[N<<3];

double yval[N<<3];

bool cmp (Node n1, Node n2) {
    if (n1.x == n2.x) return n1.flag > n2.flag; // Must calculate the positive edge first!
    return n1.x < n2.x;
}

void build(int o, int l, int r) {  
    tree[o].inv = 0;
    tree[o].l = yval[l];
    tree[o].r = yval[r];
    tree[o].sum = 0;
    if (r-l == 1) // leaf should be an interval
        return;
    int m = (l+r)>>1;
    build(o<<1, l, m); build(o<<1|1, m, r);
}

void pushup(int o) {
    tree[o].sum = max(tree[o<<1].sum, tree[o<<1|1].sum) + tree[o].inv; // maximal weithed edge + lazy mark
}

void add(int o, double l, double r, int c) { // 点修改
    if (l==tree[o].l && r==tree[o].r) {
        tree[o].inv += c; // weight of the edge
        pushup(o); 
        return;
    }
    if (l < tree[o<<1].r) add(o<<1, l, min(tree[o<<1].r, r), c); // 区间add
    if (r > tree[o<<1|1].l) add(o<<1|1, max(l, tree[o<<1|1].l), r, c); // 区间add
    pushup(o);
}

int main() {
    while (scanf("%d %d %d", &n, &w, &h)!=EOF) {
        double x, y, c;
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf %lf", &x, &y, &c);
            node[i].x = x; node[i].y1 = y; node[i].y2 = y+h-1; node[i].flag = c;
            node[i+n].x = x+w-1; node[i+n].y1 = y; node[i+n].y2 = y+h-1; node[i+n].flag = -c;
            yval[i] = y; yval[i+n] = y+h-1;
        }
        sort(node, node+2*n, cmp);
        sort(yval, yval+2*n); // use yval to build tree
        // int k = unique(yval, yval+2*n)-yval;
        build(1, 0, 2*n-1);
        add(1, node[0].y1, node[0].y2, node[0].flag);
        double ans = 0;
        for (int j = 1; j < 2*n; ++j) {
            ans = max(ans, tree[1].sum);
            // cout << tree[1].sum << endl;
            add(1, node[j].y1, node[j].y2, node[j].flag);
        }
        printf("%.0f\n", ans);
    }
	return 0;
}
/* 说白了，转化成区域后，求区域最大值，求变成了扫描线后求给定H大小的区间最大值*/
