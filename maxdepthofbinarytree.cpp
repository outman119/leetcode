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
    int maxDepth(TreeNode *root) {
       return getlen(root);
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
