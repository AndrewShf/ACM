class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int sum[105];
        int dp[105][105];
        const int inf = 0x3f3f3f3f;
        memset(sum, 0, sizeof(sum));
        for (int i = piles.size()-1; i >= 0; --i) {
            sum[i] = sum[i+1] + piles[i];
        }
        memset(dp, 0, sizeof(dp));
        for (int i = piles.size()-1; i >= 0; --i) {
            for (int j = 100; j >= 1; --j) {
                int tmp = -inf;
                if (2 * j+i > piles.size()-1) {
                    tmp = sum[i];
                } else {
                    for (int x = 1; x <= 2*j; ++x) {
                        tmp = max(tmp, sum[i] - dp[i+x][max(j, x)]);
                    }
                }
                dp[i][j] = tmp;
            }
        }
        return dp[0][1];
    }
};
// it occurs to me that, dynamic programming tests my ability to dig out and organize information in the background information.

// 状态的描述对解题有帮助。这思路看起来违反了游戏规则，实际上却没有。
// Alex从特定的index i,特定的M取stones，为了达到最大值。
