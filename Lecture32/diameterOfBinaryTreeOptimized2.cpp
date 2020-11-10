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

	int diameterOptimized(TreeNode* root, int* h) {
		int lheight = -1, rheight = -1;
		int ldiameter = 0, rdiameter = 0;
		if (root == NULL) {
			*h =  -1;
			return 0;
		}
		ldiameter = diameterOptimized(root->left, &lheight);
		rdiameter = diameterOptimized(root->right, &rheight);

		*h = max(lheight, rheight) + 1;
		int ownDiameter = lheight + rheight + 2;
		return max(ownDiameter, max(ldiameter, rdiameter));

	}

	int diameterOfBinaryTree(TreeNode* root) {
		int h = 0;
		return diameterOptimized(root, &h);
	}
};







