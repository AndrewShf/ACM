class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        if (d * f < target) return 0;
        int dp[35][1005];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= f; ++i) dp[1][i] = 1;

        for (int i = 2; i <= d; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int k = 1; k <= f; ++k) {
                    if (k < j) dp[i][j] = (dp[i-1][j-k]+dp[i][j]) % (int)(1e9+7);
                }
            }
        }
        return dp[d][target];
    }
}; // 状态定义，状态迁移（抓住不变量,已知量）
   // 状态定义：特定的dice，特定的target是一个状态
   // 状态迁移，∑dp[i-1][j-k] -> dp[i][j]
