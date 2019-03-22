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
#define ll long long
#define local

using namespace std;

const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 1e6 + 10;

int pa[maxn];
// the key code
int find(int x) {
    return x==pa[x] ? x:pa[x]=find(pa[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    pa[x] = y;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void init() {
    for (int i = 0; i < maxn; ++i) {
        pa[i] = i;
    }
}

int main() {
#ifdef local
    if (freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    int k;
    scanf("%d", &k);
    int a, b;
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &a, &b);
        unite(a, b);
    }
    bool vis[maxn];
    for (int i = 1; i <= n*m; ++i) {
        vis[find(i)] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n*m; ++i) {
        if (vis[i]) cnt++;
    }
    printf("%d\n", cnt);
#ifdef local
    fclose(stdin);
#endif
    return 0;
}



