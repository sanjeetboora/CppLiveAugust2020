/* Problem -  https://leetcode.com/problems/same-tree/ */
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL and q == NULL) {
			return true;
		}

		if (p != NULL and q != NULL) {
			bool leftSubtree = isSameTree(p->left, q->left);
			bool rightSubtree = isSameTree(p->right, q->right);
			if (p->val == q->val and leftSubtree and rightSubtree) {
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}
};