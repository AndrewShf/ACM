/*
load the data first
compress the big data to smaller one while making them in order.
sort and delete the duplicates
modify the intervals change [s, e] to (s-1, e]
use binary search to pin the position of tranformed result of the big data.
apply union and find set to this and check if there is contradiction
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
#define ll long long
#define local

using namespace std;

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const int PI = acos(-1.0);
const int maxn = 1e4+5;

int pa[maxn], r[maxn];
int num[maxn];
int cnt;
struct Edge {
    int s, e;
    int val;
} edge[maxn];

void init() {
    for (int i = 0; i < maxn; ++i) pa[i] = i;
    memset(r, 0, sizeof(r));
}

int find(int x) {
    if (x == pa[x]) return pa[x];
    int t = pa[x];
    pa[x] = find(pa[x]);
    r[x] = (r[x]+r[t]) % 2;
    return pa[x];
}

void unite(int x, int y, int op) {
    int fx = find(x);
    int fy = find(y);
    pa[fy] = fx;
    r[fy] = (op+r[x]-r[y]+2) % 2;
}

int binary_search(int x) {
    int l = -1;
    int r = cnt-1;
    while (r-l > 1) {
        int m = (l+r)>>1;
        if (num[m] >= x) r = m;
        else l = m;
    }
    return r;
}

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    int n, q;
    scanf("%d%d", &n, &q);
    char str[10];
    cnt = 0;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &edge[i].s, &edge[i].e);
        scanf("%s", str);
        if (str[0] == 'e') {
            edge[i].val = 0;
        } else {
            edge[i].val = 1;
        }
        getchar();
        edge[i].s--;
        num[cnt++] = edge[i].s;
        num[cnt++] = edge[i].e;
    }
    sort(num, num+cnt);
    cnt = int(unique(num, num+cnt) - num);
    init();
    int i;
    for (i = 0; i < q; ++i) {
        int x = binary_search(edge[i].s);
        int y = binary_search(edge[i].e);
        int val = edge[i].val;
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            unite(x, y, val);
        } else {
            if ((val+r[x])%2 != r[y]) { // Find the contradiction.
                printf("%d\n", i);
                break;
            }
        }
    }
    if (i == q) {
        printf("%d\n", q);
    }

#ifdef local
    fclose(stdin);
#endif
    return 0;
}






