/* https://www.acwing.com/problem/content/272/ */
/*
    Use segment tree to maintain pa(union-find-set) info, including its value and depth
    考虑并查集的fa数组能够表示这个并查集。所以我们只需要按照可持久化数组的套路维护fa数组即可。(每次合并进行点修改，见addNodes function)
    但众所周知，没有优化的并查集时间复杂度是每次最坏O(n)，妥妥TLE&MLE。
    考虑最常规优化：路径压缩。每一次找到根节点后把其所有祖先和自己的父亲都指向根。普通的路径压缩并查集时间复杂度为均摊O(logn).但在可持久化并查集中，这存在两个问题：
    每次修改至多O(logn)个祖先，且在可持久化数组中修改一个元素的时空代价是O(logn)，即总空间复杂度为O(mlog2n),会MLE。
    路径压缩并查集的时间复杂度是均摊的，可能存在某次操作的时间复杂度是O(n).可以构造数据，多次访问需要O(n)进行路径压缩的版本，即可让他达到最坏空间复杂度O(mnlogn),更是MLE飞。

    另一种优化：按秩合并。即按树高合并，在维护fa同时维护dep,表示以这个点所在集合的最大深度。合并时将深度小的集合合并到深度大的集合上，使最大深度不增加（如果两个集合深度相同，合并后要更新深度）。可以证明按秩合并并查集的时间复杂度为每次O(logn)O(logn).
    因此每次访问至多O(logn)个点，至多修改2个点，因此时间复杂度O(mlog2n),空间复杂度O(mlogn)

    Reference: https://www.acwing.com/solution/acwing/content/7887/

    Notice: When adding nodes to existing tree, remember to add this line:
    lson[root] = lson[pre]; rson[root] = rson[pre]; // remember to add this one! otherwise the sons information can not be retrieved!
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

const int N = 2e5+10;
const int M = 2e5+10;
int n, m, total;

struct Tree {
    int dep;
    int pa;
} tree[N<<5];
int rt[N], lson[N<<5], rson[N<<5];

int build(int l, int r) {
    int root = total++;
    if (l == r) {
        tree[root].pa = l;
        tree[root].dep = 1;
    } else {
        int m = (l+r)>>1;
        lson[root] = build(l, m);
        rson[root] = build(m+1, r);
    }
    return root;
}

int query(int o, int goal, int l, int r) {
    if (l == r) return o;
    int m = (l+r)>>1;
    if (goal <= m) return query(lson[o], goal, l, m);
    else return query(rson[o], goal, m+1, r);
}

int find(int version, int x, int l, int r) { // Use the index in range(1~n) and return node number (1 ~ n<<5)
    int xx = query(version, x, l, r);
    if (tree[xx].pa == x) return xx; // if root, then return
    return find(version, tree[xx].pa, l, r);
}

int addNodes(int l, int r, int pre, int pos, int val) {
    int root = total++;
    if (l == r) {
        tree[root].pa = val;
        return root;
    }
    int m = (l+r)>>1;
    lson[root] = lson[pre]; rson[root] = rson[pre]; // remember to add this one!
    if (pos <= m)
        lson[root] = addNodes(l, m, lson[pre], pos, val);
    else
        rson[root] = addNodes(m+1, r, rson[pre], pos, val);
    return root;
}

void addDepth(int l, int r, int root, int pos) {
    if (l == r) {
        tree[root].dep +=1;
        return;
    }
    int m = (l+r)>>1;
    if (pos <= m)
        addDepth(l, m, lson[root], pos);
    else
        addDepth(m+1, r, rson[root], pos);
}

int main() {
    scanf("%d%d", &n, &m);
    int lastans = 0;
    int op, x, y;
    total = 0;
    rt[0] = build(1, n); // ranges from 1 ~ n
    for (int i = 1; i <= m; ++i) {
        scanf("%d ", &op);
        if (op == 1) { // let depth of x is smaller than y and merge x to y
            scanf("%d %d", &x, &y);
            x = x ^ lastans; y = y ^ lastans;
            x = find(rt[i-1], x, 1, n); y = find(rt[i-1], y, 1, n);
            if (tree[x].dep > tree[y].dep) swap(x, y);
            rt[i] = addNodes(1, n, rt[i-1], tree[x].pa, tree[y].pa); // tree[x].pa is the position in range 1~n 
            if (tree[x].dep == tree[y].dep)
                addDepth(1, n, rt[i], tree[y].pa);
        } else if (op == 2) { // retrieve   
            scanf("%d", &x);
            x = x ^ lastans;
            rt[i] = rt[x];
        } else { // Query
            scanf("%d %d", &x, &y);
            x = x ^ lastans; y = y ^ lastans;
            rt[i] = rt[i-1];
            x = find(rt[i], x, 1, n); y = find(rt[i], y, 1, n);
            if (tree[x].pa == tree[y].pa) {
                puts("1");
                lastans = 1;
            }
            else {
                puts("0");
                lastans = 0;
            }
        }
    }
	return 0;
}
