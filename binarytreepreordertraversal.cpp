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
    vector<int> preorderTraversal(TreeNode *root) {
      if (root == NULL)
		{
			return vector<int>();
		}
		vector<int> ret;
		preorderBuildTree(root, ret);
		return ret;
	}
private:
	bool preorderBuildTree(TreeNode *root, vector<int> &ret)
	{
		if (root == NULL)
		{
			return false;
		}
		stack<TreeNode*> tes;
		tes.push(root);
		while (1)
		{
			if (tes.empty())
			{
				break;
			}
			auto it = tes.top();
			tes.pop();
			ret.push_back(it->val);
			if (it->right)
			{
				tes.push(it->right);
			}
			if (it->left)
			{
				tes.push(it->left);
			}
		}
	}
}
