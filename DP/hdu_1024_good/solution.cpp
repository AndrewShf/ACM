#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1e6+5;
const int inf=0x7fffffff;
int m,n;
int a[maxn];
int dp[maxn];
int maxx[maxn];
int main(){
    while(scanf("%d%d",&m,&n)==2){
        for (int i=1; i<=n; ++i) {
            scanf("%d",a+i);
        }
        memset(maxx, 0, sizeof(maxx));
        memset(dp, 0, sizeof(dp));
        int MAX=0;
        for (int i=1; i<=m; ++i) {
            MAX=-inf;
            for (int j=i; j<=n; ++j) {
                dp[j]=max(dp[j-1]+a[j], maxx[j-1]+a[j]);
                maxx[j-1]=MAX;
                MAX=max(MAX, dp[j]);
            }
        }
        printf("%d\n",MAX);
    }
    return 0;
}

