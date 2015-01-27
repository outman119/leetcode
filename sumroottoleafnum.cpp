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
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
        {
            return 0;
        }
        int ret = 0;
        ret = sumup(root, ret);

    }
private:
    int sumup(TreeNode *root, int ret)
    {
        if (root == NULL)
        {
            return 0;
        }
        int tmp = ret * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            return tmp;
        }
        return sumup(root->right, tmp) + sumup(root->left, tmp);
    }
};
