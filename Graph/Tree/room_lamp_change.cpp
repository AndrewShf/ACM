https://nanti.jisuanke.com/t/30996

题意：
题意：有n个房间，每个房间有a[i]个灯泡需要被替换。工作人员一开始有m个替换灯泡，并且每个月再增加m个。
有q组询问，问每个月已经替换完成的房间数和灯泡剩余的量。
注意：只有替换灯泡数大于房间内的灯泡数才可以替换，每次从左到右替换、当所有房间都被替换完之后或者这个月的灯泡数不够了即结束。
每次可能不止替换一个房间，因为这个wa了很多次。


利用线段树维护最小值即可

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
#define local

using namespace std;

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+5;

int ans_new[maxn], ans_left[maxn];
int q[maxn];
int room[maxn], mn[maxn << 2];
int query, n, buy, mx = 0;

void build(int o, int l, int r) {
    if (l == r) mn[o] = room[l];
    else {
        int m = (l+r) >> 1;
        build(o<<1, l, m);
        build(o<<1|1, m+1, r);
        mn[o] = min(mn[o<<1], mn[o<<1|1]);
    }
}

void add(int q, int o, int c, int l, int r) { // 点修改
    if (l == r) {
        mn[o] = c;
        return;
    }
    int m = (l+r)>>1;
    if (q <= m) add(q, o<<1, c, l, m);
    else add(q, o<<1|1, c, m+1, r);
    mn[o] = min(mn[o<<1], mn[o<<1|1]);
}

int Query(int o, int val, int month, int l, int r) {
    if (val < mn[o]) {
        ans_new[month] = max(ans_new[month-1], ans_new[month]);
        return 0;
    } else {
        while (l != r) {
            int m = (l+r) >> 1;
            if (val >= mn[o<<1]) {
                r = m;
                o = o << 1;
            } else {
                l = m+1;
                o = o << 1 | 1;
            }
        }
        if (ans_new[month] == 0)
            ans_new[month] = ans_new[month-1]+1;
        else ans_new[month]++;
        ans_left[month] = val-mn[o];
        add(l, 1, inf, 0, n-1);
        return 1;
    }
}

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    scanf("%d%d", &n, &buy);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &room[i]);
    }
    scanf("%d", &query);
    for (int i = 0; i < query; ++i) {
        scanf("%d", &q[i]);
        mx = max(mx, q[i]);
    }
    build(1, 0, n-1);
    memset(ans_new, 0, sizeof(ans_new));
    memset(ans_left, 0, sizeof(ans_left));
    int inv = mx;
    for (int i = 1; i <= mx; ++i) {
        if (ans_new[i-1] == n) {
            inv = i-1;
            break;
        } else {
            ans_left[i] = ans_left[i-1]+buy;
            while(true) {
                if (!Query(1, ans_left[i], i, 0, n-1)) break;
            }
        }
    }
    for (int i = 0; i < query; ++i) {
        if (q[i] >= inv) {
            printf("%d %d\n", ans_new[inv], ans_left[inv]);
        } else {
            printf("%d %d\n", ans_new[q[i]], ans_left[q[i]]);
        }
    }
#ifdef local
    fclose(stdin);
#endif
    return 0;
}



//5 4
//10 7
//10
//5 1 4 8 7 2 3 6 4 7

