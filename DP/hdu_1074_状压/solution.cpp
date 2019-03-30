/*
状态压缩的题：
	对于每一种状态，看他下一步能到达那些状态，并评判这种到达方式是否最优
路径记录：
	在更新最优到达方式的，更新达到的最优路径
	用递归的方式返回路径，这里因为状态有压缩，需要解压，用log2函数
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
const int maxn = 1<<16;


struct node{
    char s[maxn];
    int C,D;
}homework[20];

int dp[maxn];
int pre[maxn];

void output(int status) {
	if (status == 0) return;
	int t = log2(status-pre[status]);
	output(pre[status]);
	printf("%s\n", homework[t].s);
}

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif


    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%s%d%d", homework[i].s, &homework[i].D, &homework[i].C);
        }
        for(int i = 0; i < (1<<n); ++i) dp[i] = inf;
        dp[0] = 0;
        for(int i = 0; i < (1<<n); ++i){
            for(int j = 0; j < n; ++j){
                if(i & (1<<j)) continue; // examine the unwalked ways
                int reduce = 0;
                for(int k = 0; k < n; ++k)
                    if(i & (1<<k)) reduce+=homework[k].C;
                // to calculate the penalty time
                if(reduce + homework[j].C > homework[j].D) reduce = reduce + homework[j].C - homework[j].D;
                else reduce = 0;
                // the next stop should be optimized or not ?
                if(dp[i|(1<<j)] > dp[i] + reduce){
                    dp[i|(1<<j)] = dp[i] + reduce;
                    pre[i|(1<<j)] = i;
                }
            }
        }
        printf("%d\n", dp[(1<<n)-1]);
        output((1<<n)-1);
    }

#ifdef local
    fclose(stdin);
#endif
    return 0;
}




