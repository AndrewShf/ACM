/*

判断n及以下的邪恶数的数目
当所有数位都是由4或7组成时，称之为邪恶数

*/



/*
 
 主要思想：
 是分两步考虑 若n=12345
 那么先考虑n=9999～0
 再考虑12345～10000
 
 发现：
 9以下：4,7
 99～10：(4)4， (7)4，(7)7， (4)7    所以就是上面的总数*2
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
#define ull unsigned long long
//#define local

using namespace std;

const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 1e3 + 10;

ull n;

int cal (unsigned long long x) {
    if (x >= 77) {
        return 6;
    } else if (x >= 74) {
        return 5;
    } else if (x >= 47) {
        return 4;
    } else if (x >= 44) {
        return 3;
    } else if (x >= 7) {
        return 2;
    } else if (x >= 4) {
        return 1;
    } else return 0;
}

int main() {
#ifdef local
    if (freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    
    int l;
    scanf("%d", &l);
    while (l--) {
        scanf("%llu", &n);
        ull mod = 1;
        int cnt = 0;
        unsigned long long tmp = n;
        // 这里是计算n的位数，n=444的话，cnt=3，mod = 1000
        while (tmp) {
            mod *= 10;
            tmp /= 10;
            cnt++;
        }
        mod /= 10;
        // cnt代表位数, 如果cnt==2 代表输入的n为两位数，此时直接判断就好
        if (cnt <= 2) {
            printf("%d\n", cal(n));
        } else {
            int k = 1;
            int ans = 0;
            // 此处计算忽略n最高位时，有多少种组合。比如n=3333, 此时不考虑3333～1000,只考虑999及以下有多少种组合
            // 显然，此时的组合可以用以下循环计算
            // 比如9及以下有两个，99及以下有2+4个, 999及以下有2+4+8个
            for (int i = 1; i < cnt; ++i) {
                k *= 2;
                ans += k;
            }
            k = 1;
            // 此时计算考虑最高位的情况，若n=3333,此时考虑的是3333～1000的组合
            // 计算n的每一位从高到低
//            printf("%d  ", ans);
            int pre;
            for (int i = cnt; i > 0; --i) {
                int tmp = n/mod; //
//                printf("%d  ", tmp);
                if (tmp >= 7) {
                    k *= 2; // 如果该位 >= 7， 那么有两种选择   *2
                } else if (tmp >= 4) {
                    k *= 1; // 如果该位 >= 4; < 7， 那么有1种选择  *1
                } else { // 如果该位<4, 那么限制了之前的选择，但需要考虑上一位的值 比如n==470或者480，此时判断到最后一位 tmp=0，进入该分支
                    // 1. 470 ： 此时3位数的组合是444，447两种
                    // 2. 480 ： 此时3位数的组合是444，447，474，477
                    // 可以看出，十位数限制了选择。
                    if (pre == 7 || pre == 4) // 当pre==7，==4时，减少一种选择
                        ans += (k-1)*(pow(2, i));
                    else ans += k*pow(2, i); // 其余不用减少
                    k = 0;
                    break;
                }
                // 判断下一位 若n原来等于1234，此时mod=1000，n经过模运算==234
                n %= mod;
                mod /= 10;
                // 记录上一位的值, 是为了解决这两种情况
                // 1. 470 ： 此时3位数的组合是444，447两种
                // 2. 480 ： 此时3位数的组合是444，447，474，477
                // 可以看出，十位数限制了选择。
                pre = tmp;
            }
            if (k) {
                ans += k;
            }
            printf("%d\n", ans);
        }
    }
    
#ifdef local
    fclose(stdin);
#endif
    return 0;
}














