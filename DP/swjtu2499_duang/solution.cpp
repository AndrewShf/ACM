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

char str[maxn];
int num[maxn][8];

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        int l = strlen(str);
        for (int i = 0; i < 5; ++i) {
            num[l][i] = 0;
        }
        for (int i = l-1; i >= 0; i--) {
            if (str[i] == 'g') {
                num[i][0] = (num[i+1][0] + 1) % MOD;
                num[i][1] = num[i+1][1];
                num[i][2] = num[i+1][2];
                num[i][3] = num[i+1][3];
                num[i][4] = num[i+1][4];
            }
            if (str[i] == 'n') {
                num[i][0] = num[i+1][0];
                num[i][1] = (num[i+1][1] + num[i+1][0]) % MOD;
                num[i][2] = num[i+1][2];
                num[i][3] = num[i+1][3];
                num[i][4] = num[i+1][4];                
            }
            if (str[i] == 'a') {
                num[i][0] = num[i+1][0];
                num[i][2] = (num[i+1][2] + num[i+1][1]) % MOD;
                num[i][1] = num[i+1][1];
                num[i][3] = num[i+1][3];
                num[i][4] = num[i+1][4];                
            }
            if (str[i] == 'u') {
                num[i][0] = num[i+1][0];
                num[i][3] = (num[i+1][2] + num[i+1][3]) % MOD;
                num[i][1] = num[i+1][1];
                num[i][2] = num[i+1][2];
                num[i][4] = num[i+1][4];                
            }
            if (str[i] == 'd') {
                num[i][0] = num[i+1][0];
                num[i][4] = (num[i+1][4] + num[i+1][3]) % MOD;
                num[i][1] = num[i+1][1];
                num[i][2] = num[i+1][2];
                num[i][3] = num[i+1][3];
            }
        }
        printf("%d\n",num[0][4]);
    }

#ifdef local
    fclose(stdin);
#endif
    return 0;
}


// 166666668
















