You have N integers, A1, A2, ... , AN. You need to deal with two kinds of operations. One type of operation is to add some given number to each number in a given interval. The other is to ask for the sum of numbers in a given interval.
Input
The first line contains two numbers N and Q. 1 ≤ N,Q ≤ 100000.
The second line contains N numbers, the initial values of A1, A2, ... , AN. -1000000000 ≤ Ai ≤ 1000000000.
Each of the next Q lines represents an operation.
"C a b c" means adding c to each of Aa, Aa+1, ... , Ab. -10000 ≤ c ≤ 10000.
"Q a b" means querying the sum of Aa, Aa+1, ... , Ab.
Output
You need to answer all Q commands in order. One answer in a line.
Sample Input
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Sample Output
4
55
9
15
Hint
The sums may exceed the range of 32-bit integers.

/*A Simple Problem with Integers POJ - 3468*/
#include <iostream>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll bit0[maxn],bit1[maxn];
int n,q;
void add(ll *c,int i,int d){
    while (i<=n) {//i<=n,而不是<=MAX(max of input numbers)!
        c[i]+=d;
        i+=i&-i;
    }
}
ll sum(ll *c,int i){
    ll res=0;
    while (i>0) {
        res+=c[i];
        i=i&(i-1);
    }
    return res;
}
int main(){
    scanf("%d%d",&n,&q);
    memset(bit0, 0, sizeof(bit0));
    memset(bit1, 0, sizeof(bit1));
    int tempx;
    for(int i=1;i<=n;i++){
        scanf("%d",&tempx);
        add(bit0,i, tempx);
    }
    char op[2];
    while (q--) {
        scanf("%s",op);
//        if(op[0]=='C'){
//            int a,b,c;
//            scanf("%d%d%d",&a,&b,&c);
//            //下面的做法复杂度高，想想为什么。
//            for(int i=a;i<=b;i++) add(i, c);
//// 树状数组可以高效的求出连续的一段元素之和，或者更新单个元素的值，但是无法高效的给某个区间所有元素同时加上一个值。
//        }
        if (op[0]=='C') {
            int l,r,c;
            scanf("%d%d%d",&l,&r,&c);
            //算法设计：
            add(bit0, l, -c*(l-1));
            add(bit1, l, c);
            add(bit0, r+1, c*r);
            add(bit1, r+1, -c);
        }
        else{
            int l,r;
            scanf("%d%d",&l,&r); l--;
            ll ans=sum(bit0, r)+sum(bit1, r)*r-sum(bit0, l)-sum(bit1, l)*l;//∑ai=sum(bit0)+sum(bit1)*i
            printf("%lld\n",ans);
        }
    }
    return 0;
}



