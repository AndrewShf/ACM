/*
在你面前有一个n阶的楼梯，你一步只能上1阶或2阶。
请问计算出你可以采用多少种不同的方式爬完这个楼梯。

一个正整数n(n<=100)，表示这个楼梯一共有多少阶

very likely to overflow; so better use high and low to present one data
*/

#include<iostream>
#include<cstring>

using namespace std;

#define ll unsigned long long

ll low[105];
ll high[105];

ll k = 1e18;

void fun(ll n) {
    if (n<=2) {
        return;
    }
    if (low[n] != 0) {
        return;
    }
    else {
        fun(n-1); fun(n-2);
        low[n] = (low[n-1]+low[n-2])%(k);
        high[n] = (low[n-1]+low[n-2])/(k) + high[n-1]+high[n-2];
    }
}

int main() {
    memset(low, 0, sizeof(0));
    memset(high, 0, sizeof(0));
    low[0] = 0; low[1] = 1; low[2] = 2;
    ll n;
    scanf("%llu", &n);
    fun(n);
    if (high[n]!=0)
        printf("%llu%llu",high[n],low[n]);
    else
        printf("%llu",low[n]);
    return 0;
}
