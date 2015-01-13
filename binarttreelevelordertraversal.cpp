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
    vector<vector<int> > levelOrder(TreeNode *root) {
        if (root == NULL)
		{
			return vector<vector<int> >();
		}
		vector<vector<int> > ret;		
		queue<TreeNode*>que1;
		que1.push(root);
		TreeNode *index = root;
		vector<int>level;
		while (1)
		{
			if (que1.empty())
			{
				break;
			}
			TreeNode *ptr = que1.front();
			level.push_back(ptr->val);
			if (ptr->left)
			{
				que1.push(ptr->left);
			}
			if (ptr->right)
			{
				que1.push(ptr->right);
			}
			que1.pop();
			if (index == ptr)
			{
				ret.push_back(level);
				level.clear();
				index = que1.back();
			}
		}
		return ret;
    }
};
