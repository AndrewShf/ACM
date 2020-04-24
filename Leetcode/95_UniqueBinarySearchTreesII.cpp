/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 题目要求返回一个根的容器。
   分解子问题，每个根都有左子树，
   右子树构成。根被唯一确定时，
   根连上左子树，右子树的所有情况，就得到了根的所有情况。
*/
class Solution {
public:
    vector<TreeNode*> build(int l, int r) {
        vector<TreeNode*> ans;
        if (r == l) {
            TreeNode* p = new TreeNode(l);
            ans.push_back(p);
        } else if (r < l) {
            ans.push_back(0);
            return ans;
        } else {
            vector<TreeNode*> lv;
            vector<TreeNode*> rv;
            for (int i = l; i <= r; ++i) {
                lv = build(l, i-1);
                rv = build(i+1, r);
                for (int j = 0; j < lv.size(); ++j) {
                    for (int  k = 0; k < rv.size(); ++k) {
                        TreeNode* root = new TreeNode(i);
                        root->left = lv[j];
                        root->right = rv[k];
                        ans.push_back(root);
                    }
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if (!n) return ans;
        else ans = build(1, n);
        return ans;
    }
};