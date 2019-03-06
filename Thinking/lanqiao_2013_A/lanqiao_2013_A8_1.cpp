/*
最关键的是发现上限为a*b-1,这样可以极大的缩小枚举范围
此外利用动态规划思想，做备忘录。
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

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 1e6 + 10;

// using flag[] as memoir
bool flag[maxn];

int main() {
#ifdef local
    if(freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

    int a, b;
    cin >> a >> b;
    // assume that a > b
    if (b > a) swap(a, b);
    int ans = a+1;
    int cnt = 0;
    memset(flag, 0, sizeof(flag));
    flag[a] = true;
    flag[b] = true;
    flag[a+b] = true;
    // ***maximum of the answer is a*b-1, can be easily proved by proof by contradiction ***
    for (int i = b+1; i < a*b; ++i) {
    	if (i%a==0 || i%b==0 || i%(a+b)==0) { // can be divided
			flag[i] = true;
  			continue;
		} else {
			if (i < (a+b)) flag[i] = false;
			if (flag[i-(a+b)] == true) {
				flag[i] = true;
			} else {
				flag[i] = false; // can not be divided
				ans = i; // modify ans
			}
		}
    }
    cout << ans << endl;
#ifdef local
    fclose(stdin);
#endif
    return 0;
}
