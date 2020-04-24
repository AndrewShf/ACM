class Solution {
public:
    int longestDecomposition(string text) {
        if (text == "") return 0;
        for (int i = 1; i < text.size(); ++i) {
            if (text.substr(0, i) == text.substr(text.size()-i, i)) {
                // cout << text.substr(0, i) << endl;
                return 2 + longestDecomposition(text.substr(i, text.size()-2*i));
            }
        }
        return 1;
    }
}; // 贪心 + 递归，不是dp吧。。。
