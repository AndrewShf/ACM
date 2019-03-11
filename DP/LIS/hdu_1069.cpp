#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 35;
struct node {
    int x, y , z;
} base[3 * maxn];
int dp[maxn * 3];
bool cmp(node n1, node n2) {
    return n1.x * n1.y < n2.x * n2.y;
}
int main() {
    int n;
    int kase = 0;
    while (scanf("%d", &n) && n) {
        int cnt = 0;
        int a[3];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &a[0], &a[1], &a[2]);
            sort(a, a + 3); // to assume that .x > .y,
            base[cnt].y = a[0]; base[cnt].x = a[1]; base[cnt++].z = a[2];
            base[cnt].y = a[0]; base[cnt].x = a[2]; base[cnt++].z = a[1];
            base[cnt].y = a[1]; base[cnt].x = a[2]; base[cnt++].z = a[0];
        }
        sort(base, base + cnt, cmp);
        for (int i = 0; i < cnt; ++i) {
            dp[i] = base[i].z;
        }
        for (int i = 0; i < cnt; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (base[i].x > base[j].x && base[i].y > base[j].y)
                    dp[i] = max(dp[i], dp[j] + base[i].z);
            }
        }
        int mx = 0;
        for (int i = 0; i < cnt; ++i)
            mx = max(mx, dp[i]);
        printf("Case %d: maximum height = %d\n", ++kase, mx);
    }
    return 0;
}
