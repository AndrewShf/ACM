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
const double PI = acos(-1.0);
const int maxn = 2e4 + 10;
const int maxk = 5e4 + 10;
double dp[maxk];
int a[maxn];
double sum[maxn];

int binary_search(double val, int n) { // val should be type double
    int l = -1; int r = n-1;
    while (r-l > 1) {
        int mid = (l+r)>>1;
        if (val <= a[mid]) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r; // r should be the ans
}

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--) {
        int n, k;
        double ans;
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a+i);
        }
        sort(a, a+n);
        if (a[0] == a[n-1]) { // if all the a[i] is the same
            double ans = a[0];
            printf("Case #%d: %.6f\n", ++kase, ans);
            continue;
        }
        for (int i = 1; i <= n; ++i) { // calculate the prefix sum
            sum[i] = a[i-1]+sum[i-1];
        }
        for (int i = 1; i <= k+1; ++i) {
            int pos = binary_search(dp[i-1], n); // using binary find to get the  satisfying position
            // printf("%d   %f\n", pos, dp[i-1]);
            dp[i] = (sum[n]-sum[pos])/n + dp[i-1]/n*pos;
        }
        printf("Case #%d: %.6f\n", ++kase, dp[k+1]);

    }

#ifdef local
    fclose(stdin);
#endif
    return 0;
}



