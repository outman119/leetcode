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
    int maxPathSum(TreeNode *root) {
        if (!root)
        {
            return 0;
        }
        maxss = root->val;
        maxsum(root);
        return maxss;
    }
private:
    int maxss;
    int maxsum(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }
        auto sum = node->val;
        auto lmax = 0;
        auto rmax = 0;
        if (node->left)
        {
            lmax = maxsum(node->left);
        }
        if (node->right)
        {
            rmax = maxsum(node->right);
        }
        if (lmax > 0)
        {
            sum += lmax;
        }
        if (rmax > 0)
        {
            sum += rmax;
        }
        maxss = max(maxss, sum);
        return (max(lmax, rmax)>0?(max(lmax, rmax)+node->val):node->val);
    }
};
