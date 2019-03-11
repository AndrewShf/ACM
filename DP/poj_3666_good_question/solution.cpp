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
const int maxn = 2e3 + 10;

ll a[maxn];
ll dp[2][maxn];
ll mn[maxn];
ll b[maxn];

bool cmp(ll x, ll y) {
    return x > y;
}

ll DP(int n) {
    int e = 0;
    memset(mn, 0x3f, sizeof(mn));
    for (int i = 0; i < n; ++i) {
        dp[e][i] = abs(a[0]-b[i]);
        if (i) mn[i] = min(mn[i-1], dp[e][i]);
        else mn[i] = dp[e][i];
    }
    for (int i = 1; i < n; ++i) {
        e = 1-e;
        for (int j = 0; j < n; ++j) {
            dp[e][j] = mn[j]+abs(a[i]-b[j]);
            if (j) mn[j] = min(mn[j-1], dp[e][j]);
            else mn[j] = dp[e][j];
        }
    }
    ll ans = inf;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[e][i]);
    }
    return ans;
}

int main() {
#ifdef local
    if (freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a+i);
        b[i] = a[i];
    }
    sort(b, b+n);
    memset(dp, 0, sizeof(dp));
    ll ans = DP(n);
    sort(b, b+n, cmp);
    ans = min(ans, DP(n));
    printf("%lld\n", ans);
    
#ifdef local
    fclose(stdin);
#endif
    return 0;
}

