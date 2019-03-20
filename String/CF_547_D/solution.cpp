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
const int maxn = 15e4 + 10;

vector <int> cl[30];
vector <int> cr[30];
vector <int> fr;
vector <int> fl;

int main() {
#ifdef local
    if (freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]<='z' && s[i]>='a')
            cl[s[i]-'a'].push_back(i);
        else
            fl.push_back(i);
    }
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]<='z' && s[i]>='a')
        cr[s[i]-'a'].emplace_back(i);
        else
        fr.emplace_back(i);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < 26; ++i) {
        while (cl[i].size() && cr[i].size()) {
            ans.emplace_back(cl[i].back(), cr[i].back());
            cl[i].pop_back(); cr[i].pop_back();
        }
    }
    for (int i = 0; i < 26 && fl.size(); ++i) {
        while (cr[i].size() && fl.size()) {
            ans.emplace_back(fl.back(), cr[i].back());
            cr[i].pop_back(); fl.pop_back();
        }
    }
    for (int i = 0; i < 26 && fr.size(); ++i) {
        while (cl[i].size() && fr.size()) {
            ans.emplace_back(cl[i].back(), fr.back());
            cl[i].pop_back(); fr.pop_back();
        }
    }
    while (fl.size() && fr.size()) {
        ans.emplace_back(fl.back(), fr.back());
        fl.pop_back(); fr.pop_back();
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first+1, ans[i].second+1);
    }
#ifdef local
    fclose(stdin);
#endif
    return 0;
}





