/* http://codeforces.com/contest/948/problem/C */

树状数组：
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define INF 0x3f3f3f3f
#define lowbit(x) (x&(-x))
#define eps 0.00000001
#define pn printf("\n")
using namespace std;
typedef long long ll;

const int maxn = 1e5+5;
int n;
ll v[maxn], t[maxn], to[maxn];
ll ans[maxn];
ll c[maxn];

void update(int pos,int val)
{
    while(pos <= maxn)
    {
        c[pos] += val;
        pos += lowbit(pos);
    }
}
int query(int pos)
{
    int ret = 0;
    while(pos > 0)
    {
        ret += c[pos];
        pos -= lowbit(pos);
    }
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld", v+i);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld", t+i);
        to[i] = to[i-1] + t[i];
    }
    for(int i=1;i<=n;i++)
    {
        ll tp = v[i] + to[i-1];
        //为什么lower_bound to+n+1?
        //lower_bound的实现原理:返回的是被查序列中第一个大于等于查找值的指针
        //如果都比其小，返回最后指针的位置
        int pos = lower_bound(to+i, to+n+1, tp)-to;
        if(i < pos)//当i～pos-1 v[i]不会消失完全
        {
            update(i, 1);
            update(pos, -1);//在pos-1下面的-1，上面的+1，-1抵消
            //综合起来就是，i～pos-1 的位置数量增1
        }
        ans[pos] += tp - to[pos-1];//计算不足t[i]的
    }
    for(int i=1;i<=n;i++)
        ans[i] += 1LL * t[i] * query(i);
    for(int i=1;i<=n;i++)
    {
        if(i != 1) printf(" ");
        printf("%lld", ans[i]);
    } pn;
}


/* Priority Queue  */

#include <iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int v[maxn];
long long t[maxn];
long long sum[maxn];
int n;
priority_queue<long long ,vector<long long >,greater<long long > >q;
int main()
{
    while(cin>>n)
    {
        memset(t,0,sizeof(t));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&t[i]);
            sum[i]=sum[i-1]+t[i];//计算前缀和
        }
        for(int i=1;i<=n;i++)
        {
            long long ans=0;
            q.push(v[i]+sum[i-1]);
            while(!q.empty()&&q.top()<=sum[i])//若第j天的雪，到第i天还是没有被融化，不进入循环。
            {
                ans+=q.top()-sum[i-1];//将超出sum[i-1],但又不足sum[i]的计算了
                q.pop();
            }

            ans+=q.size()*t[i];//在队列里面的都还没有消融
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}

