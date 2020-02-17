/*
自守数是指一个数的平方的尾数等于该数自身的自然数。
例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376。请求出n以内的自守数的个数

（n+1）位的自守数出自n位的自守数。由此得出，如果知道n位的自守数a，
那么（n+1）位的自守数应当由a前面加上一个数构成。（仅对p的素因子个数为2时适用）
实际上，简化一下，还能发现如下规律：
5+6=11
25+76=101
625+376=1001
*/
#include<iostream>
#include<cmath>
#define ull unsigned long long

using namespace std;

int getPower(int n) {
    int i = 0;
    while(n) {
        i++;
        n /= 10;
    }
    return i;
}

int main() {
    int n;
    while (scanf("%d", &n) != -1) {
        if (n <= 1) {
            printf("%d\n", n+1); // 0, 1 平凡自然数
        } else if (n < 10) {
            printf("%d\n", n-2); // 5, 6 非平凡自然数
        }
        else {
            int po = getPower(n);
            ull a = 5, b = 6;
            for (int i = 2; i <= po; ++i) {
                for (int j = 1; j <= 8; ++j) {
                    ull tmp = j*pow(10,i-1)+a;
                    tmp = tmp*tmp - tmp;
                    if (tmp % (ull)(pow(10, i)) ==0 ) {
                        a = j*pow(10,i-1)+a;
                        b = (9-j)*pow(10,i-1)+b;
                        break;
                    }
                }
            }
            int cnt = 0;
            if (a > b) {
                int tmp = b;
                b = a;
                a = tmp;
            }
            if (n >= b) cnt = 2;
            else if (n < a) cnt = 0;
            else cnt = 1;
            printf("%d\n", cnt+2*po);
        }
    }
    return 0;
}
