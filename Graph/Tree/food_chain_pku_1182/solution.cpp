/*
Define: a -(1)-> b  b 吃 a
Define: a -(2)-> b  a 吃 b
Define: a -(0)-> b  a = b
r[x] 指向上结点
so, op x, y should be represented like this: x <-(op-1)- y
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
// #define local

using namespace std;

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const int PI = acos(-1.0);
const int maxn = 5e4+10;

int pa[maxn];
int r[maxn];

void init() {
	for (int i = 0; i < maxn; ++i) pa[i] = i;
	memset(r, 0, sizeof(r));
}

int find(int x) {
	if (x == pa[x]) return x;
	int t = pa[x];
	pa[x] = find(pa[x]);
	r[x] = (r[x]+r[t]) % 3; /*路径压缩的同时也更新权重值*/
	return pa[x];
}

void unite(int x, int y, int op) {
	int fx = find(x);
	int fy = find(y);
	pa[fy] = fx;
	r[fy] = (r[x]+op-r[y]+3) % 3;
}

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    init();
    int op, x, y;
    int ans = 0;
    while (k--) {
        scanf("%d%d%d", &op, &x, &y);
        if ((x>n) || (y>n)) {
            ans++;
            continue;
        }
        int fy = find(y);
        int fx = find(x);
        if (op == 1) {
            if (fx != fy) { // 根结点无关系，根据子节点关系，梳理根结点关系。
            	unite(x, y, 0); 
            } else {
                if (r[x] != r[y]) { //根结点一致， 然而子结点权重值不等，矛盾
                	ans++;
                	continue;
                }
            }
        } else if (op == 2) {
            if (x == y) {
            	ans++;
            	continue;
            } else if (fx == fy) {
                if ((r[x]-r[y]+3)%3 != 2) { // 从根结点推断两者关系，矛盾
                	ans++;
                	continue;
                }
            } else if (fx != fy) {
            	unite(x, y, 1);
            }
        }
    }
    printf("%d\n", ans);
#ifdef local
    fclose(stdin);
#endif
    return 0;
}
