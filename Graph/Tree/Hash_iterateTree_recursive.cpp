/*
树的遍历，递归 + 哈希函数
https://www.acwing.com/problem/content/859/
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
#define ll long long
#define ull unsigned long long
#define local

using namespace std;

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const int PI = acos(-1.0);
const int N = 2e4+10;

int ans[N];

struct Edge{
    int v;
    char w;
    int pre;
} edge[N*2];

int point[N];
int v[N];
int n, q, cnt = 0;
int P = 131;

void add(int u, int v, char c) {
    edge[cnt].v = v;
    edge[cnt].w = c;
    edge[cnt].pre = point[u];
    point[u] = cnt++;
}

unordered_map<ull, int> dfs(int cur, int pa) {
    unordered_map<ull, int> mp;
    mp[0] = v[cur];
    for (int e = point[cur]; ~e; e = edge[e].pre) { // ~ 按位取反，运算符
        if (edge[e].v != pa) {
            for (auto item : dfs(edge[e].v, cur)) {
                mp[edge[e].w+P*item.first] += item.second;
            }
        }
    }
    for (auto item : mp) {
        ans[cur] = max(ans[cur], item.second);
    }
    return mp;
}

int main() {
	#ifdef local
		if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
	#endif
    memset(point, -1, sizeof(point));
    memset(ans, 0, sizeof(ans));
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i+1]);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        char ch[2];
        scanf("%d%d%s", &u, &v, ch);
        add(u, v, ch[0]); add(v, u, ch[0]);
    }
    dfs(1, 0);
    while(q--) {
        int s;
        scanf("%d", &s);
        printf("%d\n", ans[s]);
    }
	#ifdef local
	fclose(stdin);
	#endif
	return 0;
}
