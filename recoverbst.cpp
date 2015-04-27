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
    void recoverTree(TreeNode *root) {
        if (root == NULL)
        {
            return;
        }
        TreeNode *n1 = NULL;
        TreeNode *n2 = NULL;
        TreeNode *prev = NULL;
        findTwoNode(root, n1, n2, prev);
        if (n1 != NULL && n2 != NULL)
        {
            auto tmp = n1->val;
            n1->val = n2->val;
            n2->val = tmp;
        }
        return;
    }
private:
    void findTwoNode(TreeNode *node, TreeNode *&n1, TreeNode *&n2, TreeNode *&prev)
    {
        if (node == NULL)
        {
            return;
        }
        findTwoNode(node->left, n1, n2, prev);
        if (prev != NULL && prev->val > node->val)
        {
            if (n1 == NULL)
            {
                n1 = prev;
                n2 = node;
            }
            else
            {
                n2 = node;
            }
        }
        prev = node;
        findTwoNode(node->right, n1, n2, prev);
    }
};
