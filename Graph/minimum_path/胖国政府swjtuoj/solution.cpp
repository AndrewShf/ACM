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
//#define local

using namespace std;

const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 105;
int dist[maxn][maxn];
int n, a, b, m, tmp;

int main() {
#ifdef local
	if (freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
		int T;
		scanf("%d", &T);
		while (T--) {
				memset(dist, 0x3f, sizeof(dist));
				scanf("%d%d%d", &n, &a, &b);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &m);
			scanf("%d", &tmp);
			dist[i][tmp - 1] = 0;
			for (int j = 1; j < m; ++j) {
				scanf("%d", &tmp);
				dist[i][tmp - 1] = 1;
						   
			}
				   
		}
				for (int k = 0; k < n; ++k)
						for (int i = 0; i < n; ++i)
								for (int j = 0; j < n; ++j)
										dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				if (dist[a - 1][b - 1] == inf) printf("-1\n");
				else printf("%d\n", dist[a - 1][b - 1]);
		   
	}
#ifdef local
	fclose(stdin);
#endif
		return 0;
}
