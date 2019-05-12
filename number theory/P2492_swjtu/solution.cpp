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
#define ull unsigned long long
using namespace std;

const int MOD = 1e9+7;
const int PI = acos(-1.0);
const ll inf = 1e18;
const int maxn = 1e2+5;

inline int pow(const int n, const int k) {
    long long ans = 1;
    for (long long num = n, t = k; t; num = num * num % MOD, t >>= 1) if (t & 1) ans = ans * num % MOD;
    return ans;
}

inline int inv(const int num) {
    return pow(num, MOD - 2);
}

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    int t;
    scanf("%d", &t);
    ll n, m;
    while (t--) {
        scanf("%lld%lld", &n, &m);
        ll down = (n-1)%MOD*(n-2)%MOD*(n-3)%MOD*(n-4)*n%MOD;
        ll up = (n-m)*(n-m-1)%MOD*(n-m-2)%MOD*(n-m-3)%MOD*5%MOD;
        printf("%lld\n", up*inv(down) % MOD);
    }



#ifdef local
    fclose(stdin);
#endif
    return 0;
}