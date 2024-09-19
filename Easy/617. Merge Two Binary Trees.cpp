/**
    Problem: https://leetcode.com/problems/merge-two-binary-trees/description/
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
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return NULL;
        int val1 = root1 == NULL ? 0 : root1->val;
        int val2 = root2 == NULL ? 0 : root2->val;

        TreeNode* leftNode1 = root1 == NULL ? NULL : root1->left;
        TreeNode* leftNode2 = root2 == NULL ? NULL : root2->left;

        TreeNode* rightNode1 = root1 == NULL ? NULL : root1->right;
        TreeNode* rightNode2 = root2 == NULL ? NULL : root2->right;

        TreeNode* newLeft = mergeTrees(leftNode1, leftNode2);
        TreeNode* newRight = mergeTrees(rightNode1, rightNode2);

        return new TreeNode(val1+val2, newLeft, newRight);
    }
};