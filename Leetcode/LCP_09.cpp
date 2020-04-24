/*
https://leetcode-cn.com/problems/zui-xiao-tiao-yue-ci-shu/
Reverse-DP
*/
class Solution {
public:
    int minJump(vector<int>& jump) {
        int len = jump.size();
        int* dp = new int[len+5];
        dp[len-1] = 1;
        for (int i = len-2; i >= 0; --i) {
            dp[i] = i+jump[i]>=len ? 1:dp[i+jump[i]]+1;
            /*important: dp[j]>=dp[i]+1, to ensure the value at the right of i, is always smaller than dp[i]+2*/
            for (int j = i+1; j<len && dp[j]>=dp[i]+1; ++j)
                dp[j] = dp[i]+1;
        }
        return dp[0];
    }
};
