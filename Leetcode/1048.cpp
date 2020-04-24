class Solution {
public:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int res = 0;
        for (string w : words) {
            int best = 0;
            int n = w.length();
            for (int i = 0; i < n; i++) {
                string word = w.substr(0, i) + w.substr(i + 1);
                best = max(best, dp[word] + 1);
                if (best == n) break;
            }
            dp[w] = best;
            res = max(res, best);
            if (res >= 16) return res;
        }
        return res;
    }
};
