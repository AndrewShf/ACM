class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> hor(m, vector<int>(n, 0));
        vector<vector<int>> ver(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    hor[i][j] = (j==0) ? 1:hor[i][j-1]+1;
                    ver[i][j] = (i==0) ? 1:ver[i-1][j]+1;
                }
            }
        }

        int mx = 0;
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                int small = min(hor[i][j], ver[i][j]);
                while (small > mx) { // otherwise there is no need to update
                    if (hor[i-small+1][j] >= small && ver[i][j+1-small] >= small) {
                        mx = small;
                        break;
                    }
                    small--;
                }
            }
        }
        return mx*mx;
    }
};
/*
https://leetcode.com/problems/largest-1-bordered-square/discuss/345265/c%2B%2B-beats-100-(both-time-and-memory)-concise-with-algorithm-and-image

https://www.geeksforgeeks.org/given-matrix-o-x-find-largest-subsquare-surrounded-x/
*/
// note：that has all 1s on its border, "all" 不准确。
/*首先想最简单的做法：N^4,遍历每个方形然后check是否符合规定。
然后利用空间信息，来简化复杂度
有了hor, ver之后，我们确定每一个点，它能组成最大的正方形就是small = min(hor[i][j], ver[i][j]),然后再在 small上面向下枚举即可。
*/
