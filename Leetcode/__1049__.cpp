class Solution {
public:
    int lastStoneWeightII(vector<int>& A) {
        bitset<3001> dp = {1}; // like bool.
        int sumA = 0;
        for (int a : A) {
            sumA += a;
            for (int i = sumA; i >= a; --i)
                dp[i] = dp[i] + dp[i - a];
        }
        for (int i = sumA / 2; i > 0; --i)
            if (dp[i]) return sumA - i - i;
        return 0;
    }
};
// divide to 2 groups, minimize the difference of the __sum__ of the 2 groups
// it is equivalent in math
// calculate the sum? dp[sum] = (dp[sum]==1 ? 1:dp[sum-a])
// from a-sumA should all be checked.
