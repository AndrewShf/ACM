class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector <char> dp[1005][1005];
        dp[0][0] = {};
        dp[1][0] = {};
        dp[0][1] = {};
        int n = str1.size();
        int m = str2.size();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                    dp[i][j].push_back(str1[i-1]);
                } else {
                    if (dp[i][j-1].size() > dp[i-1][j].size())
                        dp[i][j] = dp[i][j-1];
                    else dp[i][j] = dp[i-1][j];
                }
            }
        }
        if (dp[n][m].size() == 0) return str2+str1;
        string str;
        int pos1 = 0, pos2 = 0;
        for (int i = 0; i < dp[n][m].size();) {
            char tmp = dp[n][m][i];
            if (tmp != str1[pos1]) {
                str.append(str1.substr(pos1, 1));
                pos1++;
            }
            if (tmp != str2[pos2]) {
                str.append(str2.substr(pos2, 1));
                pos2++;
            }
            if (tmp == str1[pos1] && tmp == str2[pos2]) {
                str.append(str1.substr(pos1, 1));
                pos1++;
                pos2++;
                ++i;
            }
        }
        if (pos1 < str1.size())
            str.append(str1.substr(pos1, str1.size()-pos1));
        if (pos2 < str2.size())
            str.append(str2.substr(pos2, str2.size()-pos2));
        return str;
    }
};
// Longest common substring + track the path
// As a result, using a vector<char> to save the path of the longest sizes.
// 优化，不用vector<char>, 用string就好了。。。哎。
// 616ms, 287M
