/*
Greedy Algorithm
O(N) time complexity
"hops"
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
#include <unordered_map>
#include <stack>
#include <deque>

#define ll long long
#define ull unsigned long long

using namespace std;

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int PI = acos(-1.0);

const int N = 25000+10;
const int T = 1e6+10;
int n, t;

int arr[N];
int nex[T];

int main() {
    scanf("%d%d", &n, &t);
    memset(nex, 0, sizeof(nex));
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        nex[l] = max(nex[l], r); // the farest right point 'l' can reach
    }
    for (int i = 1; i <= t; ++i) {
        nex[i] = max(nex[i], nex[i-1]); // start early than i, end late than i; recalculate!
    }
    int p = 1;
    int ans = 0;
    while (p<=t && nex[p]>=p) p = nex[p]+1, ans++;
    if (p > t) printf("%d\n", ans); // p == t is not OK
    else puts("-1");
	return 0;
}
