#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    for (; n != 0;) //输入数字（决定礼物个数）
    {
        int ans = 0;
        for (; n > 0; n--) //输入每个礼物的编号
        {
            int a;
            scanf("%d", &a);
            ans ^= a; //进行位运算
        }
        printf("%d\n", ans);
        scanf("%d", &n); 
    }
};
