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
    int minDepth(TreeNode *root) {
		return getminlen(root, 0);

	}
private:
	int getminlen(TreeNode *root, int len)
	{
		if (root == NULL )
		{
			return len;
		}
		len++;
		if (root->left == NULL
			&& root->right == NULL)
		{
			return len;
		}
		if (root->left == NULL)
		{
			return getminlen(root->right, len);
		}
		if (root->right == NULL)
		{
			return getminlen(root->left, len);
		}
		int leftlen = getminlen(root->left, len);
		int rightlen = getminlen(root->right, len);
		if (leftlen > rightlen)
		{
			return rightlen;
		}
		return leftlen;

	}
};
