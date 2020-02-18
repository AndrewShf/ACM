/*
find local minimum  time complexity O(log n)

定义局部最小的概念。arr长度为1时，arr[0]是局部最小。
arr的长度为N(N>1)时，如果arr[0]<arr[1]，那么arr[0]是局部最小；
如果arr[N-1]<arr[N-2]，那么arr[N-1]是局部最小；如果0<i<N-1，既有arr[i]<arr[i-1]，
又有arr[i]<arr[i+1]，那么arr[i]是局部最小。
给定无序数组arr，已知arr中任意两个相邻的数不相等。
写一个函数，只需返回arr中任意一个局部最小出现的位置即可

若不在0, n-1处，那么两端则是下降的趋势
在二分的时候，往两端都是下降趋势去靠拢（则必会交于一处）

*/

#include<iostream>

using namespace std;

const int N = 1e5+10;

int main() {
    int n;
    int a[N];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    if (n==1) {
        printf("%d\n", 0);
        return 0;
    } else if (a[0]<a[1]) {
        printf("%d\n", 0);
        return 0;
    } else if (a[n-1]<a[n-2]) {
        printf("%d\n", n-1);
        return 0;
    }
    int l = -1,  r = n-1;
    while(r-l>1) {
        int mid = (l+r)/2;
        if (a[mid]<a[mid+1] && a[mid]<a[mid-1]) {
            printf("%d\n", mid);
            return 0;
        } else if (a[mid]>a[mid-1]){
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%d\n", r);
    return 0;
}
