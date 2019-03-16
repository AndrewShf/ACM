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
const int maxn = 1e5 + 10;

ll a[maxn], tmp[maxn];

int main() {
#ifdef local
    if (freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        ll mod = 1;
        ll ans = 0;
        for (int i = 0; i < n; ++i) scanf("%lld", a+i);
        // 考虑进位总是麻烦事，怎么样能够解决呢？
        // 进位可分为9种，个位进位，十位进位，百位进位...这样计算就没问题了，可用二分。
        for (int k = 1; k <= 9; ++k) {
            mod *= 10;
            for (int i = 0; i < n; ++i) tmp[i] = a[i]%mod;
            sort(tmp, tmp+n);
            // lower_bound : return the first num whose value not lower than given number
            for (int i = 0; i < n; ++i) ans += n - (lower_bound(tmp+i+1, tmp+n, mod-tmp[i]) - tmp);
            // printf("%d\n", ans);
        }
        printf("%lld\n", ans);
    }

#ifdef local
    fclose(stdin);
#endif
    return 0;
}




