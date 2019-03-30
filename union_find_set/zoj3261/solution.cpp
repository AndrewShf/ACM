
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
const int PI = acos(-1.0);
const int HASH  =  10000;   
const int maxn = 1e5;

const int N  =  10005;   
const int M  =  20005;   
 
map < int,  bool > mp;   
  
int f[N];   
int rank[N];   
int n, m, Q;   
int ans[50005];    // 保存答案  
  
struct Buit {
      
        int u,  v;   
} built[M];   
  
struct Query {
      
        char cmd[10];   
        int a,  b;   
} query[50005];   
  
void make_set() {
      
        for (int i = 0;  i < n;  ++i) f[i] = i;   
}  
int find(int x) {
      
        int i, j = x;   
        while (j != f[j]) j = f[j];   
        while (x != j) {i = f[x];  f[x] = j;  x = i;}  
        return j;   
}  
void Union(int x, int y) {
      
        int a = find(x), b = find(y);;   
        if (a == b)return ;   
        if (rank[a] > rank[b]) f[b] = a;   
        else if (rank[a] < rank[b]) f[a] = b;   
        else {
          
                if (a > b) f[a] = b;   
                else f[b] = a;   
            
    }   
}  

int main() {
#ifdef local
    if (freopen("/Users/Andrew/Desktop/data.txt", "r", stdin) == NULL) printf("can't open this file!\n");
#endif

        bool flag = false;   
        while (~scanf("%d", &n)) {
          
                for (int i = 0;  i < n;  ++i)  
                        scanf("%d", &rank[i]);   
                scanf("%d", &m);   
                for (int i = 0;  i < m;  ++i) {
              
                        scanf("%d%d", &built[i].u,  &built[i].v);   
                        if (built[i].u > built[i].v) {
                  
                                swap(built[i].u,  built[i].v);   
                            
            }  
                    
        }  
                scanf("%d", &Q);   
                mp.clear();   
                for (int i = 0;  i < Q;  ++i) {
              
                        scanf("%s", query[i].cmd);   
                        if (query[i].cmd[0] == 'q') scanf("%d", &query[i].a);   
                        else {
                  
                                scanf("%d%d", &query[i].a, &query[i].b);   
                                if (query[i].a > query[i].b) swap(query[i].a, query[i].b);   
                                mp[query[i].a * HASH + query[i].b] = true;;   
                            
            }  
                    
        }  
                // 合并没有删除的边  
                make_set();   
                for (int i = 0;  i < m;  ++i)if (!mp[built[i].u * HASH + built[i].v]) {
                  
                            Union(built[i].u,  built[i].v);   
                        
            }  
                // 询问  
                int k = 0;   
                for (int i = Q - 1;  i >= 0;  --i) {
              
                        if (query[i].cmd[0] == 'q') {
                  
                                int fa = find(query[i].a);   
                                if (rank[fa] > rank[query[i].a]) ans[k++] = fa;   
                                else ans[k++] = -1;   
                            
            }  
                        else { // 否则合并
                  
                                Union(query[i].a, query[i].b);   
                            
            }  
                    
        }  
                if (flag)puts("");   
                else flag = true;   
                for (int i = k - 1;  i >= 0;  --i)  // 逆向输出答案
                        printf("%d\n",  ans[i]);   
            
    }  

#ifdef local
    fclose(stdin);
#endif
    return 0;
}




