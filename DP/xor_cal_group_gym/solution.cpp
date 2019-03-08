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
const int maxn = 105;

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    int T;
    scanf("%d", &T);
    int n;
    ll dp[maxn][130];
    while(T--) {
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i)
            dp[i][i] = 1;
        int m;
        for(int i = 1; i <= n; ++i) { // number needed to be divided
            for(int j = 0; j < 128; ++j) { // result can be approached, because there are only 8 bits
                for(int k = 1; k <= i; ++k) { // number divided into k
                    m = k^j;
                    dp[i][j] = (dp[i][j]+dp[i-k][m])%MOD;
                }
            }
        }
        ll ans = 0;
        for(int j = 1; j < 128; ++j) {
            ans = (ans+dp[n][j])%MOD;
        }
        cout<<ans<<endl;
    }
#ifdef local
    fclose(stdin);
#endif
    return 0;
}
