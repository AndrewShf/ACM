将n个石子分成若干份，求每份的石子数异或和为正整数的方案数，如n=5时，将石子分成1,1,3，那么1 xor 1 xor 3=3，这种方案是合法方案，两种方案不同当且仅当分成的份数不同或者某一份中石子个数不同，如1 1 3和1 3 1为不同的方案
Input
第一行为T表示T组数据 接下来有T行，每行一个数字n(1<=n<=100)表示每份的石子个数
Output
输出T行表示每组询问的答案
Sample Input
2
1
3
Sample Output
1
4

Hint:
using the given number of the stone and the destination(xor result, range from 1to 128), to describe the status, dp[i][j], represents how many groups can be divided under this circumstance.
dp[i][j] = ∑dp[i-k][m], m^k = j

Remember:if  a^b = c --> a^c = b ; c^b = a
Notice:counting how many groups -> 动态规划转换方程，总是将总数分成两部分，有些是，两边都是继续再细化问题。而这道题，一部分会继续细化，另一部分为枚举出来的整数



