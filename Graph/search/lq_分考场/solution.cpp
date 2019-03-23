/*
无向图的染色问题
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
#define local

using namespace std;

const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 1e2 + 10;

bool mp[maxn][maxn]; // mp[i][j] = 1 means i-th element and j-th element are connected.
int room[maxn][maxn]; // room[i][j]: i-th room and j-th position. if it is x then this position is occupied by x
int mn;
int n;

void dfs(int x, int r) {
    if (r >= mn) return; // this branch can be ignored
    if (x > n) { // it's time to count the result and end this branch.
        mn = min(r, mn);
        return;
    }
    for (int i = 1; i <= r; ++i) { // to place x in 1~r-th room
        int k = 0;
        // the following process goes like this
        // if: the room's k-th position is occupied, check the owner and x whether they are connected
            // if connected, judge the next room
            // if not continue enumerating the next postion.
        // else: it is not occupied and no one is connected with x, x can be placed in the i-th room
        while (room[i][k] && !mp[x][room[i][k]])
            k++;
        if (room[i][k] == 0) {
            room[i][k] = x;
            dfs(x+1, r);
            room[i][k] = 0; // backtracking
        }
    }
    room[r+1][0] = x;
    dfs(x+1, r+1);
    room[r+1][0] = 0;
}

int main() {
#ifdef local
    if (freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    int m;
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        mp[a][b] = 1;
        mp[b][a] = 1;
    }
    mn = n;
    // to init r as 0, is very important. Intuitively, r can be set as 1, and it will be very time-consuming.
    // though answer is the same.
    dfs(1, 0); 
    printf("%d\n", mn);

#ifdef local
    fclose(stdin);
#endif
    return 0;
}



