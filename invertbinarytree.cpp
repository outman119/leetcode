/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
        {
            return root;
        }
        auto node1 = invertTree(root->left);
        auto node2 = invertTree(root->right);
        root->left = node2;
        root->right = node1;
        return root;
    }
};
