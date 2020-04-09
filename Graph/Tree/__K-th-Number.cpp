K-th Number
Time Limit: 20000MS	Memory Limit: 65536K
Total Submissions: 68878	Accepted: 24387
Case Time Limit: 2000MS
Description
You are working for Macrohard company in data structures department. After failing your previous task about key insertion you were asked to write a new data structure that would be able to return quickly k-th order statistics in the array segment. 
That is, given an array a[1...n] of different integer numbers, your program must answer a series of questions Q(i, j, k) in the form: "What would be the k-th number in a[i...j] segment, if this segment was sorted?" 
For example, consider the array a = (1, 5, 2, 6, 3, 7, 4). Let the question be Q(2, 5, 3). The segment a[2...5] is (5, 2, 6, 3). If we sort this segment, we get (2, 3, 5, 6), the third number is 5, and therefore the answer to the question is 5. 
Input
The first line of the input file contains n --- the size of the array, and m --- the number of questions to answer (1 <= n <= 100 000, 1 <= m <= 5 000). 
The second line contains n different integer numbers not exceeding 109 by their absolute values --- the array for which the answers should be given. 
The following m lines contain question descriptions, each description consists of three numbers: i, j, and k (1 <= i <= j <= n, 1 <= k <= j - i + 1) and represents the question Q(i, j, k). 
Output
For each question output the answer to it --- the k-th number in sorted a[i...j] segment. 
Sample Input
7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
Sample Output
5
6
3


// binary search + segment tree...

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
const int maxn = 1e5+10; // 5
const double PI = acos(-1.0);

vector <ll> v[maxn<<2];
ll a[maxn];

void bulid(int o, int l, int r) {
    if (l == r) {
        v[o].push_back(a[l]);
    } else {
        int m = (l+r)>>1;
        bulid(o<<1, l, m);
        bulid(o<<1|1, m+1, r);
        v[o].resize(r-l+1); // merge 2 sorted arrays into one sorted array
        merge(v[o<<1].begin(), v[o<<1].end(),
              v[o<<1|1].begin(), v[o<<1|1].end(), v[o].begin());
        
    }
}

int query(int o, int l, int r, int ql, int qr, ll val) {
    if (l>=ql && r<=qr) {
        return int(upper_bound(v[o].begin(), v[o].end(), val)-v[o].begin());
    } else {
        int m = (l+r)>>1;
        int ans = 0;
        if (m >= ql)
            ans += query(o<<1, l, m, ql, qr, val);
        if (m < qr)
            ans += query(o<<1|1, m+1, r, ql, qr, val);
        return ans;
    }
}

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    int n, m;
    scanf("%d%d", &n ,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    bulid(1, 0, n-1);
    sort(a, a+n);
    int i, j, k;
    for (int ii = 0; ii < m; ii++) {
        scanf("%d%d%d", &i, &j, &k);
        int l = -1; int r = n-1;
        while (r-l > 1) {
            int mid = (l+r)>>1;
            if (query(1, 0, n-1, i-1, j-1, a[mid]) >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("%lld\n", a[r]);
    }
#ifdef local
    fclose(stdin);
#endif
    return 0;
}

