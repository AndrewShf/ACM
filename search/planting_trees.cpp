/*
Only, 95% pass
cut branches, dfs
*/
/*
to get 100%, the method is somewhat strange
iterate the kinds array to get current mx; add this at the beginning of DFS
O(N)
However, it succeeds.

https://www.nowcoder.com/practice/52f25c8a8d414f8f8fe46d4e62ef732c?tpId=98&&tqId=32964&rp=2&ru=/activity/oj&qru=/ta/2019test/question-ranking
*/
#include<iostream>

using namespace std;

const int N = 1005;
const int M = 2005;
int n, m = 0, sum;
int v[N];
int ans[M];

void fillRest(int no, int kind) {
    for (int i = no; i < m;) {
        ans[i++] = kind;
        for (int j = 0; j < n; ++j) {
            if (v[j] && j != kind) {
                ans[i++] = j;
                v[j]--;
                break;
            }
        }
    }
}

bool dfs(int no, int kind) {
    ans[no] = kind;
    v[kind]--;
    sum--;
    if (no == m-1)
        return 1;
    for (int i = 0; i < n; ++i) {
        if (i != kind && v[i]) {
            if (v[i]*2-1 > sum) continue; // cut branches: can not arrange proper sequence!!!
            if (v[i]*2-1 == sum) {
                fillRest(no+1, i);
                return true;
            }
            if (dfs(no+1, i))
                return 1;
        }
    }
    sum++;
    v[kind]++;
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", v+i);
        m += v[i];
    }
    sum = m;
    for (int i = 0; i < n; ++i) {
        if (dfs(0, i))
            break;
    }
    for (int i = 0; i < m; ++i) {
        if (i)
            printf(" %d", ans[i]+1);
        else
            printf("%d", ans[i]+1);
    }
    printf("\n");
    return 0;
}
