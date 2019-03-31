/*
划分数，高精度，分位计算
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
const int PI = acos(-1.0);
const ll inf = 1e18;
const int maxn = 1005;
const int maxm = 105;

ll low[maxn][maxm];
ll high[maxn][maxm];

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    memset(low, 0, sizeof(low));
    memset(high, 0, sizeof(high));
    low[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            low[i][j] = low[i][j-1]; // if i < j, dp[i][j] = dp[i][j-1]
            high[i][j] = high[i][j-1];
            if (i >= j) { // if i >= j, dp[i][j] = dp[i][j-1]+dp[i-j][j]
                low[i][j] = (low[i][j-1] + low[i-j][j]) % inf;
                high[i][j] = (high[i][j-1] + high[i-j][j] + (low[i][j-1] + low[i-j][j]) / inf);
            }
        }
    }
    if (high[n][k] != 0)
        printf("%lld", high[n][k]);
    printf("%lld\n", low[n][k]);

#ifdef local
    fclose(stdin);
#endif
    return 0;
}



