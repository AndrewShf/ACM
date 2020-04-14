/* 树的直径（最长路） 的详细证明
主要是利用了反证法：

假设 s-t这条路径为树的直径，或者称为树上的最长路

现有结论，从任意一点u出发搜到的最远的点一定是s、t中的一点，然后在从这个最远点开始搜，就可以搜到另一个最长路的端点，即用两遍广搜就可以找出树的最长路
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
const double PI = acos(-1.0);
const int maxn = 2e4 + 10;

struct Edge {
	int w, v;
};

vector <Edge> v[maxn];
bool visit[maxn];
int mx = -1;
int subans;
int node;

void dfs(int cur, int val) {
	visit[cur] = 1;
	if (val > subans) {
		subans = val;
		node = cur; //the first dfs, find the wanted node.
	}
	for (int i = 0; i < v[cur].size(); ++i) {
		if (visit[v[cur][i].v] == 0)
			dfs(v[cur][i].v, val+v[cur][i].w);
	}
	visit[cur] = 0;
}

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    int n;
    scanf("%d", &n);
    int p, q, d;
    Edge tmp;
    for (int i = 0; i < n-1; ++i) {
    	scanf("%d%d%d", &p, &q, &d);
    	tmp.w = d; tmp.v = q;
    	v[p].push_back(tmp);
    	tmp.v = p;
    	v[q].push_back(tmp); //two ways
    }
    subans = -1;
    dfs(1, 0); // randomly choose one node, and use dfs to obtain the one of the two nodes which form the max length.
    dfs(node, 0);
    mx = max(mx, subans);
    printf("%d\n", mx*10+(1+mx)*mx/2);
#ifdef local
    fclose(stdin);
#endif
    return 0;
}
