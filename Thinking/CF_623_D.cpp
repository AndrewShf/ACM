// http://codeforces.com/contest/1315/problem/D
// Greedy
// time complexity limitation
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
#define local

using namespace std;

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const int PI = acos(-1.0);

const int N = 2e5+10;

vector<int> arr;
unordered_map<int, vector<pair<int, int>>> mp;
int penalty[N];
priority_queue<int, vector<int>, greater<int>> q;

bool cmp (pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {
	#ifdef local
		if(freopen("/Users/Andrew/Desktop/Problems/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
	#endif

    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        cin >> penalty[i];
        mp[arr[i]].emplace_back(i, penalty[i]);
    }
    sort(arr.begin(), arr.end(), less<int>());
    auto newend = unique(arr.begin(), arr.end());
    arr.erase(newend, arr.end());
    for (int i = 0; i < arr.size(); ++i) {
        q.push(arr[i]);
    }
    priority_queue<ll, vector<ll>, less<ll>> s;
    ll sums = 0;
    for (int i = 0; q.size(); ++i) {
        int top = q.top();
        q.pop();
        // insert
        for (int j = 0; j < mp[top].size(); ++j) {
            s.push(mp[top][j].second);
            sums += mp[top][j].second;
        }
        // delete
        int top2 = inf;
        if (!q.empty())
            top2 = q.top();
        for (int j = 0; (j<top2-top) && (s.size()); ++j) {
            sums -= s.top();
            s.pop();
            ans += sums;
        }
    }
    // for (int i = 0; i < arr.size(); ++i) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;    
    cout << ans << endl;

	#ifdef local
	fclose(stdin);
	#endif
	return 0;
}
