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
const int maxn = 1e3 + 10;

int loop[maxn];

int main() {
#ifdef local
    if (freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    int cnt = 1;
    a = (a%b)*10;
    int looplen = 1;
    int start;
    while (cnt - n <= 2) {
        if (cnt >= n) {
            printf("%d", a/b);
        }
        a = (a%b)*10;
        cnt++;
    }
    printf("\n");

#ifdef local
    fclose(stdin);
#endif
    return 0;
}



