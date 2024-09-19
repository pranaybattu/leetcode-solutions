/**
    Problem: https://leetcode.com/problems/validate-binary-search-tree/description/
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool isValidBST(TreeNode* root, long left, long right) {
        if(root == NULL) return true;

        if(left >= root->val || root->val >= right) return false;

        return isValidBST(root->left, left, root->val) && isValidBST(root->right, root->val, right);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return isValidBST(root->left, LONG_MIN, root->val) && isValidBST(root->right, root->val, LONG_MAX);
    }
};