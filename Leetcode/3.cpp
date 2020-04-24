use sliding window
keep track of the character's position, and for the left side of the window, in the process of moving, remove the previous character's position.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int ans = 0;
        int a[150];
        memset(a, -1, sizeof(a));
        int p = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (a[s[i]-' '] == -1) {
                a[s[i]-' '] = i;
            } else {
                while (s[p] != s[i]) {
                    a[s[p]-' '] = -1;
                    p++;
                }
                p++;
                a[s[i]-' '] = i;
            }
            ans = max(ans, i-p+1);
        }
        return ans;
    }
};
// 28ms, >68%
