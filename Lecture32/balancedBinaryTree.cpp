//https://leetcode.com/problems/balanced-binary-tree/
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
    bool balanced;
};

Pair isHeightBalanced(TreeNode* root) {
    Pair p;
    if (root == NULL) {
        p.height = -1;
        p.balanced = true;
        return p;
    }

    Pair leftSubtree = isHeightBalanced(root->left);
    Pair rightSubtree = isHeightBalanced(root->right);
    p.height = max(leftSubtree.height, rightSubtree.height) + 1;
    if (abs(leftSubtree.height - rightSubtree.height) <= 1 and leftSubtree.balanced and rightSubtree.balanced) {
        p.balanced = true;
    }
    else {
        p.balanced = false;
    }
    return p;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        Pair sol = isHeightBalanced(root);
        return sol.balanced;
    }
};