/*
首先a,b分开装东西，不会比他们合在一起装东西装的多。（反证法）

其次，如果从大到小枚举可行的lecture note，如果每次先考虑a，那么a最后肯定可以被装满。

所以，剩下的lecture note，给b，b一定装的下所有。
*/
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
const int maxn = (1e5+10);
const int maxedge = 100*100;
ll a, b;

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    
    scanf("%lld%lld", &a, &b);
    vector <ll> ansa, ansb;
    ll x = 1;
    for (; 1LL*x*(x+1)/2 <= a+b; ++x) ;
    x--;
    for (; x > 0; x--) {
        if (a >= x) {
            ansa.push_back(x);
            a -= x;
        } else if (b >= x) {
            ansb.push_back(x);
            b -= x;
        }
    }
    printf("%d\n", int(ansa.size()));
    for (int i = 0; i < ansa.size(); ++i) {
        printf("%lld", ansa[i]);
        if (i != ansa.size()-1) printf(" ");
    }
    cout << endl;
    printf("%d\n", int(ansb.size()));
    for (int i = 0; i < ansb.size(); ++i) {
        printf("%lld", ansb[i]);
        if (i != ansb.size()-1) printf(" ");
    }
    cout << endl;
    
#ifdef local
    fclose(stdin);
#endif
    return 0;
}
