In the game of DotA, Pudge’s meat hook is actually the most horrible thing for most of the heroes. The hook is made up of several consecutive metallic sticks which are of the same length. 
Now Pudge wants to do some operations on the hook. 
Let us number the consecutive metallic sticks of the hook from 1 to N. For each operation, Pudge can change the consecutive metallic sticks, numbered from X to Y, into cupreous sticks, silver sticks or golden sticks. 
The total value of the hook is calculated as the sum of values of N metallic sticks. More precisely, the value for each kind of stick is calculated as follows: 
For each cupreous stick, the value is 1. 
For each silver stick, the value is 2. 
For each golden stick, the value is 3. 
Pudge wants to know the total value of the hook after performing the operations. 
You may consider the original hook is made up of cupreous sticks. 
 Input
The input consists of several test cases. The first line of the input is the number of the cases. There are no more than 10 cases. 
For each case, the first line contains an integer N, 1<=N<=100,000, which is the number of the sticks of Pudge’s meat hook and the second line contains an integer Q, 0<=Q<=100,000, which is the number of the operations. 
Next Q lines, each line contains three integers X, Y, 1<=X<=Y<=N, Z, 1<=Z<=3, which defines an operation: change the sticks numbered from X to Y into the metal kind Z, where Z=1 represents the cupreous kind, Z=2 represents the silver kind and Z=3 represents the golden kind. 
Output
For each case, print a number in a line representing the total value of the hook after the operations. Use the format in the example. 
Sample Input
1 10 2 1 5 2 5 9 3 
Sample Output
Case 1: The total value of the hook is 24.
/* Interval change in Segment Tree; Need lazy mark */
/*模版题 hdu1698 just a hook*/
#include<iostream>
#include <cstring>
using namespace std;
const int maxn=1e5+5;
int n,q,ql,qr,val;
int a[maxn],sum[maxn<<2],inv[maxn<<2];
void bulid(int o,int l,int r){
    inv[o]=0;//建树，将所有懒惰标记初始化
    if(l==r)
        sum[o]=a[l];
    else{
        int m=(l+r)>>1;
        bulid(o<<1, l, m);bulid(o<<1|1, m+1, r);
        sum[o]=sum[o<<1]+sum[o<<1|1];//pushup操作，向父结点返回值
    }
}
void pushdown(int o,int ln,int rn){
    //由于用法，懒惰标记只可能向下遍历，并且是在下一次更新或者查询操作中
    //有懒惰标记表明此结点没有继续往下更新
    if(inv[o]){
        sum[o<<1]=ln*inv[o];//由于父结点区间都被要求更新，子结点一定是所有元素都被更新
        sum[o<<1|1]=rn*inv[o];
        inv[o<<1]=inv[o<<1|1]=inv[o];
        inv[o]=0;//消除标记
        //同时不用考虑叶子被懒惰标记后，导致违规访问的情况
    }
}
void add(int o,int l,int r,int val){
    if(ql<=l&&qr>=r){
        sum[o]=(r-l+1)*val;
        inv[o]=val;//若此结点的val被全部更新，此结点加上一个懒惰标记，值为更新值
    }
    else{
        int m=(l+r)>>1;
        pushdown(o, m-l+1, r-m);//检查是否有之前遍历的懒惰标记
        if(ql<=m) add(o<<1, l, m, val);//同点修改
        if(qr>m) add(o<<1|1, m+1, r, val);
        //向上返回值时，不需要加懒惰标记，因为父结点不是全部值都要求被更新
        sum[o]=sum[o<<1]+sum[o<<1|1];
    }
}
int query(int o,int l,int r){
    if(ql<=l&&qr>=r)
        return sum[o];
    int m=(l+r)>>1;
    pushdown(o, m-l+1, r-m);//下推，否则可能sum有误
    int res=0;
    if(ql<=m) res+=query(o<<1, l, m);
    if(ql>m) res+=query(o, m+1, r);
    return res;
}
int main(){
    int T,kase=0;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) a[i]=1;
        bulid(1, 1, n);
        while (q--) {
            scanf("%d%d%d",&ql,&qr,&val);
            add(1, 1, n, val);
        }
        printf("Case %d: The total value of the hook is %d.\n",++kase,sum[1]);
    }
    return 0;
}

