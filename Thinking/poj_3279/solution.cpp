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

const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 2e1 + 10;

int a[maxn][maxn];
int flip[maxn][maxn];
int ans[maxn][maxn];
int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int cnt = 0;
int mncnt = inf;
int flag;
int n, m;

bool judge(int x, int y) {
    int num = 0;
    for (int i = 0; i < 5; ++i) {
        int xx = dir[i][0]+x;
        int yy = dir[i][1]+y;
        // xx is the first dimention, should be smaller than m
        if (xx<m && xx>=0 && yy>=0 && yy<n)
            num += flip[xx][yy];
    }
    // count the initial status
    num += a[x][y];
    return num&1;
}

void solve() {
    // enumerate the possible circumstances in the first row. And it is enough.
    for (int i = (1<<n)-1; i >= 0; --i) { 
        flag = 0;
        cnt = 0;
        memset(flip, 0, sizeof(flip));

        for (int j = 0; j < n; ++j) {
            flip[0][j] = (i>>j)&1;
            if (flip[0][j]) cnt++;
        }
        // Under a particular circumstance, every move is determined.
        for (int j = 1; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if (judge(j-1, k)) {
                    flip[j][k] = 1;
                    cnt++;
                }
            }
        }
        // the last row
        for (int j = 0; j < n; ++j) {
            // if the last row needs to be flipped, the question has no answer.
            if (judge(m-1, j)) {
                flag = 1;
                break;
            }
        }
        // if the solution is possible and cnt is smaller.
        if (!flag && cnt<=mncnt) {
            memcpy(ans, flip, sizeof(ans)); // choose the ans with smaller lexicon
            mncnt = cnt;
        }
    }

    // print answer:
    if (mncnt == inf) printf("IMPOSSIBLE\n");
    else {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j) printf(" %d", ans[i][j]);
                else printf("%d", ans[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
#ifdef local
    if (freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    solve();

#ifdef local
    fclose(stdin);
#endif
    return 0;
}




