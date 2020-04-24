/*
Given four lists A, B, C, D of integer values, 
compute how many tuples (i, j, k, l) there are 
such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, 
all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
All integers are in the range of -228 to 228 - 1 and 
the result is guaranteed to be at most 231 - 1.
*/

/*
折半枚举
*/


class Solution {
public:
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // merge A,B to ab and C,D to cd
        vector<int> ab, cd; int ans = 0;
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < B.size(); ++j)
                ab.emplace_back(A[i]+B[j]);
        for (int i = 0; i < C.size(); ++i)
            for (int j = 0; j < D.size(); ++j)
                cd.emplace_back(C[i]+D[j]);
        sort(ab.begin(), ab.end()); 
        sort(cd.begin(), cd.end());
        int tmp;
        for (int i = 0; i < ab.size(); ++i) {
            if (i && ab[i] == ab[i-1]) {
                ans += tmp;
                continue;
            }
            tmp = upper_bound(cd.begin(), cd.end(), -ab[i]) - lower_bound(cd.begin(), cd.end(), -ab[i]);
            // cout << tmp << endl;
            ans += tmp;
        }
        return ans;
    }
};