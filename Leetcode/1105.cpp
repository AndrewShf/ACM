class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int dp[1005];
        const int inf = 0x3f3f3f3f;
        dp[0] = 0;
        dp[1] = books[0][1];
        for (int i = 1; i < books.size(); ++i) {
            dp[i+1] = dp[i]+books[i][1];
            int mx = books[i][1];
            int w = books[i][0];
            for (int j = 1; j <= i; ++j) {
                mx = max(mx, books[i-j][1]);
                w += books[i-j][0];
                if (w > shelf_width) break;
                else dp[i+1] = min(dp[i+1], dp[i-j]+mx);
            }
        }
        return dp[books.size()];
    }
};

// books[i]只有两种选择，一个是单独一堆，一个是和别人一组。和别人一组不知道前面可不可以，就枚举从1到j的情况（都满足宽度的限制）
// 犯了一个错误，不一定是相邻的状态互相递推，有可能是很前面的状态递推过来的。
