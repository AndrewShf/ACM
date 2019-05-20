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

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const int maxn = 305;
int N;
int c[maxn][maxn];
int inque[maxn];
int dist[maxn];

void spfa (int start, int end) {
    queue<int> q;
    inque[start] = 0;
    dist[start] = inf;
    for (int i = 1; i <= N; ++i) {
        if(i == start) continue;
        dist[i] = c[start][i];
        inque[i] = 1;
        q.push(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        inque[u] = 0;
        for (int i = 1; i <= N; i++) {
            if(dist[i] > dist[u]+c[u][i]) {
                dist[i] = dist[u]+c[u][i];
                if(!inque[i]) {
                    inque[i] = 1;
                    q.push(i);
                }
            }
        }
    }
}

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    while (cin >> N) {
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                scanf("%d", &c[i][j]);
        spfa(1, N);
        int ans = dist[N];
        int c1 = dist[1];
        spfa(N, N);
        int c2 = dist[N];
        printf("%d\n", min(ans, c1+c2));
    }
#ifdef local
    fclose(stdin);
#endif
    return 0;
}
