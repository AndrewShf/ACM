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
#define ull unsigned long long
#define local
using namespace std;

const int MOD = 1e9+7;
const int PI = acos(-1.0);
const ll inf = 1e18;
const int maxn = 2e5+5;



int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    if (n < 2) {
        if (n == 1) printf("%d\n", b);
        else printf("%d\n", a);
    } else {
        if (n % 3 == 0) printf("%d\n", a);
        else if (n % 3 == 1) printf("%d\n", b);
        else printf("%d\n", a^b);
    }
#ifdef local
    fclose(stdin);
#endif
    return 0;
}

