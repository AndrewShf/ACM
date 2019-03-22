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

int f[maxn];

int main() {
#ifdef local
    if (freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    string s1, s2;
    cin >> s1;
    cin >> s2;

    memset(f, 0, sizeof(f));
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i])
            f[i+1] = 1;
        // printf("%d  ", f[i]);
    }
    int match = 0;
    int ans = 0;
    for (int i = 1; i <= s1.size(); ++i) {
        if (f[i] == 1) {
            if (match == 0) {
                match = i;
            } else {
                ans += i-match;
                match = 0;
            }
        }
    }
    printf("%d\n", ans);

#ifdef local
    fclose(stdin);
#endif
    return 0;
}

