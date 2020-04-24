class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // row
        int m = matrix[0].size(); // column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j)
                    matrix[j][i] += matrix[j-1][i];
            }
        }
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                unordered_map <int, int> counter;
                counter[0] = 1;
                int cur = 0;
                for (int k = 0; k < m; ++k) {
                    cur += matrix[j][k] - (i==0 ? 0:matrix[i-1][k]);
                    res += counter[cur-target];
                    counter[cur]++;
                }
            }
        }
        return res;
    }
};
/*
For each row, calculate the prefix sum.
For each pair of columns,
calculate the accumulated sum of rows.
Now this problem is same to, 'Find the Subarray with Target Sum'.
The last 'for' is the method to solve 'subarray with Target Sum'.
*/
