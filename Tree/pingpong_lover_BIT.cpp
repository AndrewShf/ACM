/*
N (3 ≤ N ≤ 20000) ping pong players live along a west-east street(consider the street as a line segment). Each player has a unique skill rank. To improve their skill rank, they often compete with each other. If two players want to compete, they must choose a referee among other ping pong players and hold the game in the referee’s house. For some reason, the contestants can’t choose a referee whose skill rank is higher or lower than both of theirs. The contestants have to walk to the referee’s house, and because they are lazy, they want to make their total walking distance no more than the distance between their houses. Of course all players live in different houses and the position of their houses are all different. If the referee or any of the two contestants is different, we call two games different. Now is the problem: how many different games can be held in this ping pong street? 
**Input** 
The first line of the input contains an integer T (1 ≤ T ≤ 20), indicating the number of test cases, followed by T lines each of which describes a test case. 
Every test case consists of N + 1 integers. The first integer is N , the number of players. Then N distinctintegersa1,a2...aN follow,indicatingtheskillrankofeachplayer,intheorderofwesttoeast (1 ≤ ai ≤ 100000, i = 1...N). 
**Output**
For each test case, output a single line contains an integer, the total number of different games. 
**Sample Input** 
1 3123 
**Sample Output**
1 
*/

/*uvalive 4329 */
#include<iostream>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
const int maxn=2e4+5;
const int maxscore=1e5+5;
int a[maxn];
int c[maxscore]/*树状数组*/;
int s1[maxn],s2[maxn];
int MAX=0;
int lowbit(int x){
    return x&-x;
}
void add(int x,int d){
    while (x<=MAX) {
        c[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int x){
    int res=0;
    while (x>0) {
        res+=c[x];
        x-=lowbit(x);//x=x&(x-1);
    }
    return res;
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            MAX=max(a[i], MAX);//算出x的最大值
        }
        memset(c, 0, sizeof(c));
        for (int i=1; i<=n; i++) {
            s1[i]=sum(a[i]);//统计小于a[i]的数有多少
            add(a[i], 1);//从左至右计数，对于大于a[i]值的都+1
        }
        memset(c, 0, sizeof(c));
        for (int i=n; i>=1; i--) {//与上面相同，只不过从右至左计数
            s2[i]=sum(a[i]);
            add(a[i], 1);
        }
        ll ans=0;
        for(int i=2;i<n;i++) ans+=s1[i]*(n-i-s2[i])+(i-1-s1[i])*s2[i];
        printf("%lld\n",ans);
    }
    return 0;
}
/* can be implemented by segment trees*/
/* BIT can not optimize interval change effectively, but segment tree can */
