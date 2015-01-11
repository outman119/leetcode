/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
		if (root == NULL)
		{
			return true;
		}
		int leftlen = getlen(root->left);
		int rightlen = getlen(root->right);
		if (abs(leftlen - rightlen) > 1)
		{
			return false;
		}
		return isBalanced(root->left) && isBalanced(root->right);
	}
private:
	int getlen(TreeNode *root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int leftlen = 1;
		int rightlen = 1;
		leftlen += getlen(root->left);
		rightlen += getlen(root->right);
		return leftlen > rightlen ? leftlen : rightlen;
	}
};
