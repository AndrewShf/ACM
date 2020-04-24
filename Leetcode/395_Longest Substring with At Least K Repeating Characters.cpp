/*
Find the length of the longest substring T of a given string 
(consists of lowercase letters only) 
such that every character in T appears no less than k times.
*/

/*
先想简单一些，一些特殊情况，比如出现的所有数的出现次数都>=k，此时直接返回正确答案就好了
如果有没有出现>=k次的，如果字串一定包含，那么肯定不满足条件，该字串放弃。

也可以从反证法的思想去看。
*/

/*
写成了递归。先统计前缀数组，然后遇到不满足的字符，进行递归查询。
*/

class Solution {
public:
    int prefix[10000][30];
    
    int substring(string s, int start, int end, int k) {
        if (end < start) return 0;
        for (int i = start; i <= end; ++i) {
            // examine prefix of letters
            if (prefix[end+1][s[i]-'a'] - prefix[start][s[i]-'a'] < k) {
                return max(substring(s, start, i-1, k), substring(s, i+1, end, k));
            }
        }
        return end-start+1;
    }
    
    int longestSubstring(string s, int k) {
        memset(prefix, 0, sizeof(prefix));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j <= 'z'-'a'; ++j) {
                prefix[i+1][j] = prefix[i][j];
                if (j == s[i]-'a') prefix[i+1][j]++;
            }
        }
        // recursive    
        return substring(s, 0, s.size()-1, k);
    }
};