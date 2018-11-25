/*
计算所有的9个方框。方框中心的点只有可能在黑框，白框或者在外面。中心点在黑框中则按照黑色渲染了棋盘计算，其余同理。

详细见代码。

注意点：

1.题目上方框的信息给出的是方块号的信息而非坐标信息。需要转换成坐标信息

2.求两者的中点得用double转换，如果用float转换精度会有偏差。

3.sort函数应该是sort(x+1, x+5)，心态崩了。
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
const int maxn = 3e5 + 10;
ll x1, x2, x3, x4;
ll y11, y2, y3, y4;

int judge(ll lowx, ll lowy, ll highx, ll highy) {
    double x = double(lowx + highx)/2.0;
    double y = double(lowy + highy)/2.0;
    if (x>x3 && x < x4 && y > y3 && y < y4) {
        return 2;
    } else if (x>x1 && x < x2 && y > y11 && y < y2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    
    int q;
    scanf("%d", &q);
    ll n, m;
    ll x[5], y[5];
    while (q--) {
        scanf("%lld%lld", &n, &m);
        ll white = n*m/2;
        ll black = n*m/2;
        if ((n*m) % 2) {
            white++;
        }
        scanf("%lld%lld%lld%lld", &x1, &y11, &x2, &y2);
        scanf("%lld%lld%lld%lld", &x3, &y3, &x4, &y4);
        x1 -= 1; x3 -= 1;
        y11 -= 1; y3 -= 1;
        x[1] = x1; x[2] = x2;
        x[3] = x3; x[4] = x4;
        sort(x+1,x+5);
        y[1] = y11; y[2] = y2;
        y[3] = y3; y[4] = y4;
        sort(y+1, y+5);
        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j < 4; ++j) {
                if (x[i+1]==x[i] || y[j+1]==y[j]) continue;
                ll tmp = (x[i+1]-x[i])*(y[j+1]-y[j]);
                if (judge(x[i], y[j], x[i+1], y[j+1]) == 0) {
                    continue;
                } else if (judge(x[i], y[j], x[i+1], y[j+1]) == 1) {
                    if (tmp % 2) {
                        if ((x[i] + y[j]) % 2 == 0) {// white
                            white += tmp/2;
                            black -= tmp/2;
                        }
                        else {
                            white += tmp/2 + 1;
                            black -= (tmp/2+1);
                        }
                    } else {
                        white += tmp/2;
                        black -= tmp/2;
                    }
                } else {
                    if (tmp % 2) {
                        if ((x[i] + y[j]) % 2 == 1) {// black
                            white -= tmp/2;
                            black += tmp/2;
                        }
                        else {
                            white -= (tmp/2+1);
                            black += (tmp/2+1);
                        }
                    } else {
                        white -= tmp/2;
                        black += tmp/2;
                    }
                }
            }
        }
        printf("%lld %lld\n", white, black);
    }
    
#ifdef local
    fclose(stdin);
#endif
    return 0;
}
/*
思路2:
可以证明得到：白色与黑色相交方块的左下角坐标是:(max(x1, x3), max(y1, y3)) 右下角坐标是（min（x2, x4）, min(y2, y4)），无需分类讨论
*/
