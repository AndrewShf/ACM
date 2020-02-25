/*
https://www.nowcoder.com/practice/ff8cba64e7894c5582deafa54cca8ff2?tpId=101&tqId=33081&rp=1&ru=/activity/oj&qru=/ta/programmer-code-interview-guide/question-ranking

一个栈中元素的类型为整型，现在想将该栈从顶到底按从大到小的顺序排序，只许申请一个栈。除此之外，可以申请新的变量，但不能申请额外的数据结构。如何完成排序？
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
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include<sstream>

#define ll long long
#define ull unsigned long long
#define local

using namespace std;

const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;
const int PI = acos(-1.0);

int n;
stack<int> stk;
bool isSorted = 0;

void sort_stack(stack<int>& stk) { // when return, make sure all current elements in stack are sorted
    if (stk.size() <= 1) {
        isSorted = 1;
        return;
    }
    int a = stk.top(); stk.pop();
    int b = stk.top(); stk.pop();
    if (a < b) swap(a, b);
    int tmp;
    if (!isSorted)
        sort_stack(stk); // add this to reduce stack overflow
    
    if (stk.size()) tmp = stk.top();
    stk.push(b);
    if (b < tmp) sort_stack(stk);
    tmp = stk.top();
    stk.push(a);
    if (a < tmp) sort_stack(stk);
}

int main() {
	#ifdef local
		if(freopen("/Users/Andrew/Desktop/Problems/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
	#endif

    scanf("%d", &n);
    int tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        stk.push(tmp);
    }
    sort_stack(stk);
    printf("%d", stk.top());
    stk.pop();
    while (!stk.empty()) {
        printf(" %d", stk.top());
        stk.pop();
    }
    printf("\n");
	#ifdef local
	fclose(stdin);
	#endif
	return 0;
}
