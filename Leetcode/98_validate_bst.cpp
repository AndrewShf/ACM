/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

*/

/*
carefully analyze the problem. all nodes from the subtree should satisfy the condition
so in-order should visit the nodes'value from small to big.
*/

class Solution {
public:
    vector<int> v;
    bool flag = 1;
    void travel(TreeNode* root) {
        if (root == NULL) return;
        if (flag == 0) return;
        int rv = root->val;
        if (root->left)
            travel(root->left);
        if (v.size()) {
            if (rv > v.back()) v.push_back(rv);
            else {
                flag = 0;
                return;
            }
        } else v.push_back(rv);
        if (root->right) travel(root->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return 1;
        travel(root);
        return flag;
    }
};

/*
[10,5,15,null,null,6,20]
*/