/* Problem - //https://leetcode.com/problems/diameter-of-binary-tree/ */
/* By Sanjeet Boora */


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

    int height(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }
        int h = 1 + max(height(root->left), height(root->right));
        return h;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int diameterWithRoot = height(root->left) + height(root->right) + 2;
        int diameterLeftSubtree = diameterOfBinaryTree(root->left);
        int diameterRightSubtree = diameterOfBinaryTree(root->right);

        return max(diameterWithRoot, max(diameterLeftSubtree, diameterRightSubtree));
    }

};








