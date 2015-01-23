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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int>ret;
		if (root == NULL)
		{
			return ret;
		}
		stack<TreeNode*> st;
		auto ptr = root;
		while(1)
		{
			while (ptr)
			{
				st.push(ptr);
				ptr = ptr->left;
			}
			if (st.empty())
			{
				break;
			}
			ptr = st.top();
			ret.push_back(ptr->val);
			st.pop();
			ptr = ptr->right;
		}
		return ret;
    }
};
