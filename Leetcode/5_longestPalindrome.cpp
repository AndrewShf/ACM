class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1005][1005];
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
        }
        int mx = 1;
        int mxi = 0, mxj = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            for (int j = i+1; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (j-i == 1) dp[i][j] = 2;
                    else if (dp[i+1][j-1] == 0) dp[i][j] = 0;
                    else dp[i][j] = dp[i+1][j-1]+2;
                    if (dp[i][j] > mx) {
                        mx = dp[i][j];
                        mxi = i;
                        mxj = j;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        if (s.size()) {
            return s.substr(mxi, mx);
        } else return "";
    }
};