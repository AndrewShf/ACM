/*
    https://leetcode-cn.com/contest/weekly-contest-185/problems/minimum-number-of-frogs-croaking/
    通过统计字符，来检验是否能够匹配为字符串
    如果有了新的（蛙叫）开头，那么让这个开头为以前结束的（蛙叫）k执行
*/

class Solution {
    int arr[10];
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        memset(arr, 0, sizeof(arr));
        int cur = 0;
        for (char ch : croakOfFrogs) {
            if (ch == 'c') {
                cur = 0;
            } else if (ch == 'r') {
                cur = 1;
            } else if (ch == 'o') {
                cur = 2;
            } else if (ch == 'a') {
                cur = 3;
            } else if (ch == 'k') {
                cur = 4;
            }
            if (cur == 0) {
                // can be replaced by the same frog
                if (arr[4] > 0) arr[4]--;
                arr[0]++;
            } else { // check if the condition is satisfied.
                if (arr[cur-1] == 0) return -1;
                else arr[cur-1]--;
                arr[cur]++;
            }
        }
        for (int i = 0; i < 4; ++i)
            if (arr[i] != 0) return -1;
        return arr[4];
    }
};
