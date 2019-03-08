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

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 1e4 + 10;

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    
    int T;
    scanf("%d", &T);
    ll n, ans, d = 1e16;
    int kase = 0;
    while (T--) {
        scanf("%lld", &n);
        d = 1e16; // iterate 16 times
        ans = 0;
        while (d != 1) {
            ll tmp = n;
            n /= d;
            d /= 10;
            if (n == 0) {
                n = tmp;
                continue;
            } else {
                if (n&1) {
                    ll t = 8;
                    for (ll i = 1; i < d; i*=10) { // this is the place should be paid the most attention! i should be long long type, if not, TLE
                        t = t*10+8;
                    }
                    if (n == 9) {
                        ans += abs(tmp-t*10-8);
                        n = 0;
                        break;
                    } else {
                        ll sub = tmp%(d*10);
                        if (sub < t/2) // 44..444 is the line to indicate whether add or minus is a better choice
                            ans += abs(tmp-(n-1)*d*10-t);
                        else {
                            ans += d*10-sub;
                        }
                        n = 0;
                        break;
                    }
                } else {
                    n = tmp%(d*10);
                    continue;
                }
            }
        }
        if (n&1) {
            ans += 1;
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    
#ifdef local
    fclose(stdin);
#endif
    return 0;
}

/*
 Case #1: 3457
 Case #2: 543
 Case #3: 9457
 Case #4: 1110
 Case #5: 99855
 Case #6: 568
 Case #7: 239535
 Case #8: 252995346
 Case #7: 39535
 Case #8: 52995346*/


