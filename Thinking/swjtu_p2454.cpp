/*
题目：给一个数字（<2e9）每次操作可删除一个数字，求最少的操作能让它为x^2（x是正整数）
来源：swjtu-oj  p2454
思路：枚举所有x^2<=2e9的，转换成字符串,匹配x和给定的数字。
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
//#define local

using namespace std;

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 1e5 + 10;

char s[20];

void solve(double n) {
    queue <double> q;
    q.push(n);
    q.push(0);
    while(q.size()) {
        double tmp = q.front();
        q.pop();
        double cnt = q.front();
        q.pop();
        double k = sqrt(tmp);
        if ((ceil(k) == k) && k) {
            //printf("%lf\n", k);
            printf("%d\n", int(cnt));
            return;
        } else {
            ll nn = (ll)tmp;
            sprintf(s,"%lld", nn);
            int len = strlen(s);
            ll tmp1, tmp2, ans;
            for (int i = 0; i < len; ++i) {
                ans = 0;
                tmp1 = 0;
                tmp2 = 0;
                sprintf(s,"%lld", nn);
                if (i==0 && s[1]=='0') continue;
                else s[i] = ':';
                if (i>0 && i != len-1)
                    sscanf(s,"%lld:%lld",&tmp1, &tmp2);
                else if (!i)
                    sscanf(s,":%lld", &tmp2);
                else
                    sscanf(s,"%lld:", &tmp1);
                ans += tmp1*pow(10, len-i-1);
                ans += tmp2;
                if (!ans) continue;
                q.push(ans);
                q.push(cnt+1);
            }
        }
    }
    printf("-1\n");
}

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    double n;
    while(~scanf("%lf", &n)) {
        solve(n);
    }
#ifdef local
    fclose(stdin);
#endif
    return 0;
}











