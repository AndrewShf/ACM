Problem Description
Given a n*n matrix Cij (1<=i,j<=n),We want to find a n*n matrix Xij (1<=i,j<=n),which is 0 or 1.

Besides,Xij meets the following conditions:

1.X12+X13+...X1n=1
2.X1n+X2n+...Xn-1n=1
3.for each i (1<i<n), satisfies ∑Xki (1<=k<=n)=∑Xij (1<=j<=n).

For example, if n=4,we can get the following equality:

X12+X13+X14=1
X14+X24+X34=1
X12+X22+X32+X42=X21+X22+X23+X24
X13+X23+X33+X43=X31+X32+X33+X34

Now ,we want to know the minimum of ∑Cij*Xij(1<=i,j<=n) you can get.
Hint

For sample, X12=X24=1,all other Xij is 0.
 

Input
The input consists of multiple test cases (less than 35 case).
For each test case ,the first line contains one integer n (1<n<=300).
The next n lines, for each lines, each of which contains n integers, illustrating the matrix C, The j-th integer on i-th line is Cij(0<=Cij<=100000).
 

Output
For each case, output the minimum of ∑Cij*Xij you can get.
 

Sample Input
4
1 2 4 10
2 0 1 1
2 2 0 5
6 3 1 2
 

Sample Output
3
 

Author
Snow_storm

Hint:
读懂题很考人。很容易就当成水题来做了。
借鉴网上的思路。转化成最短路来做。

由（1）得知，1结点只有一个出度
由（2）得知，n结点只有一个入度
由（3）得知，其余结点出度 == 入度

一下两种情况满足上述三种规则：
A） 1到n形成一条路--->求1到n的最短路
B） 1和n没有路---> 1和n各自形成非自环的闭环。
求两者的最小值，即为题目要求的∑(Cij * Xij)
细节：求非自环的闭环：不将dist[start]初始化为0，将其初始化为inf(也就是说到start到start的路不再是自环，需要另找一条路)，在队列q中放入与之相邻的点。dist[start] 则是满足要求的最小环。



