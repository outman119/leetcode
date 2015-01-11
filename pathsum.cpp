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
    bool hasPathSum(TreeNode *root, int sum) {
		return addvla(root, sum, 0);
	}
private:
	bool addvla(TreeNode *root, int sum, int add){
		if (root == NULL)
		{
			return false;
		}
		add += root->val;
		if (root->left == NULL && root->right == NULL)
		{
			if (add == sum)
			{
				return true;
			}
		}
		if (root->left == NULL)
		{
			return addvla(root->right, sum, add);
		}
		if (root->right == NULL)
		{
			return addvla(root->left, sum, add);
		}
		return addvla(root->right, sum, add) || addvla(root->left, sum, add);
	}
};
