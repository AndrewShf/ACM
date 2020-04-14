/*
    https://www.acwing.com/problem/content/532/
    多个线段树进行维护，值域线段树，动态分配节点
    Reference:
    https://blog.csdn.net/qq_38678604/article/details/78575672
    https://www.lagou.com/lgeduarticle/5024.html
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

const int N = 3e5+10;

int n, m, q, mx, total = 0;

int sum[N<<5], lson[N<<5], rson[N<<5], rt[N];
vector<ll> G[N]; // N max time of query

int query(int root, int l, int r, int k) {
    if (l == r) {
        return l; // return the real position
    }
    int m = (l+r) >> 1;
    int num = m-l+1-sum[lson[root]]; // adjust element's position
    if (k > num) return query(rson[root], m+1, r, k-num);
    else return query(lson[root], l, m, k);
}

void add(int& root, int l, int r, int pos) {
    if (root == 0) root = ++total; // dynamically assigning new space!
    sum[root]++; // add from top to bottom of this tree if pos is in the interval
    if (l < r) {
        int m = (l+r) >> 1;
        if (pos <= m) add(lson[root], l, m, pos);
        else add(rson[root], m+1, r, pos);
    }
}

ll verticalSeg(int root, int l, int r, int k, ll v) { // segment tree formed bythe last column
    int pos = query(rt[root], l, r, k); add(rt[root], 1, mx, pos);
    // cout << "pos" << pos << endl;
    ll ans = pos > n ? G[root][pos-n-1]: 1ll * m * pos;
    G[root].emplace_back(v ? v:ans); // v==0 or v!=0
    return ans;
}

ll horizonalSeg(int root, int l, int r, int k) { // n number of segment tree from n rows all without the rightmost element
    int pos = query(rt[root], l, r, k); add(rt[root], 1, mx, pos);
    ll ans = pos >= m ? G[root][pos-m]: 1ll*(root-1)*m + pos; 
    G[root].emplace_back(verticalSeg(n+1, 1, mx, root, ans));
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    mx = max(n, m) + q; // maximal size of segment tree 
    memset(sum, 0, sizeof(sum));
    memset(rt, 0, sizeof(rt));
    memset(lson, 0, sizeof(lson));
    memset(rson, 0, sizeof(rson));
    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (y == m) {
            printf("%lld\n", verticalSeg(n+1, 1, mx, x, 0));
        } else {
            printf("%lld\n", horizonalSeg(x, 1, mx, y));
        }
    }
    return 0;
}
