// divide and conquer
class Solution {
public:
    int divide_and_conquer(const vector<int>& h, int l, int r) {
        if (r < l) return 0;
        if (r == l) return h[r];
        int pos = 0, mn = 0x3f3f3f3f;
        for (int i = l; i <= r; ++i) {
            if (h[i] < mn) {
                mn = h[i];
                pos = i;
            }
        }
        return max(mn*(r-l+1), max(divide_and_conquer(h, l, pos-1), divide_and_conquer(h, pos+1, r)));
    }
    int largestRectangleArea(vector<int>& heights) {
        return divide_and_conquer(heights, 0, heights.size()-1);
    }
};



