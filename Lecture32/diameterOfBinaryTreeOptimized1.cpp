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
class Pair {
public:
    int height;
    int diameter;
};
class Solution {
public:

    Pair diameterOptimized(TreeNode* root) {
        // pair<int, int> p; //  pair<height, diameter>
        Pair P;
        if (root == NULL) {
            P.height = -1;
            P.diameter = 0;
            return P;
        }

        Pair leftSubtree = diameterOptimized(root->left);
        Pair rightSubtree = diameterOptimized(root->right);

        P.height = max(leftSubtree.height, rightSubtree.height) + 1;
        int ownDiamter = leftSubtree.height + rightSubtree.height + 2;

        P.diameter = max(ownDiamter, max(leftSubtree.diameter, rightSubtree.diameter));
        return P;

    }

    int diameterOfBinaryTree(TreeNode* root) {
        Pair ans = diameterOptimized(root);
        return ans.diameter;
    }

};


