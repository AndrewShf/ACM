#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = 105;
int n, k;
int a[maxn][maxn];
int d[maxn][maxn];
bool judge(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}
int dfs(int x, int y) {
    int& ans = d[x][y];
    if (ans) return ans;
    for (int i = 1; i <= k; ++i) {
        if (judge(i + x, y) && a[i + x][y] > a[x][y]) {
            ans = max(ans, dfs(i + x, y));
                   
        }
           
    }
        for (int i = -1; i >= -k; --i) {
                if (judge(i + x, y) && a[i + x][y] > a[x][y]) {
                        ans = max(ans, dfs(i + x, y));
                   
        }
           
    }
    for (int i = 1; i <= k; ++i) {
        if (judge(x, i + y) && a[x][i + y] > a[x][y]) {
            ans = max(ans, dfs(x, i + y));
        }
    }
        for (int i = -1; i >= -k; --i) {
                if (judge(x, i + y) && a[x][i + y] > a[x][y]) {
                        ans = max(ans, dfs(x, i + y));
                   
        }
           
    }
    ans += a[x][y];
    return ans;
}
int main() {
    while (scanf("%d%d", &n, &k) && n != -1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        memset(d, 0, sizeof(d));
//        for(int i = 0;i < n; ++i){
//            for(int j = 0; j < n; ++j){
//                ans=max(ans, dfs(i,j));
//            }
//        }
        printf("%d\n", dfs(0, 0));
    }
    return 0;
}

