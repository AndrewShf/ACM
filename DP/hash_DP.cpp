// 头条笔试题 哈希+dp 理解题意
// https://www.acwing.com/problem/content/description/858/
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
#include <unordered_set>
#define ll long long
#define ull unsigned long long
#define local

using namespace std;

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const int PI = acos(-1.0);
const int maxn = 1e4+10;

char tem[maxn];
char words[maxn];
unordered_set<ull> s;

const int P = 131;
ull h[maxn];
ull p[maxn];

ull get(int l, int r) {
    l--;
    r--;
    if (l == 0)
        return h[r];
    return h[r]-h[l-1]*p[r-l+1];
}

bool f[maxn];

int main() {
	#ifdef local
		if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
	#endif

    scanf("%s", tem);
    int len = strlen(tem);
    for (int i = 0; i < len; ++i) {
        if (i) {
            p[i] = p[i-1]*P;
            h[i] = h[i-1]*P + tem[i];
        } else {
            h[i] = tem[i];
            p[i] = 1;
        }
    }
    while(scanf("%s", words) != -1) {
        int len = strlen(words);
        ull tot = 0;
        for (int i = 0; i < len; ++i)
            tot = tot*P + words[i];
        s.insert(tot);
    }
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 1; i <= len; ++i) {
        for (int j = i; j > 0; j--) {
            if (f[j-1] && s.count(get(j, i))) {
                f[i] = 1;
                break;
            }
        }
    }
    if (f[len])
        printf("True\n");
    else
        printf("False\n");
    
	#ifdef local
	fclose(stdin);
	#endif
	return 0;
}
