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
    bool isValidBST(TreeNode *root) {
        if (root == NULL)
        {
            return true;
        }
        if (root->left == NULL &&
            root->right == NULL)
        {
            return true;
        }
        if (root->left)
        {
            int maxleft = max(root->left);
            if (maxleft >= root->val)
            {
                return false;
            }
        }
        if (root->right)
        {
            int minright = min(root->right);
            if (minright <= root->val)
            {
                return false;
            }
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
private:
    int max(TreeNode*root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int max = root->val;
        queue<TreeNode*>tree;
        tree.push(root);
        while (1)
        {
            if (tree.empty())
            {
                break;
            }
            auto node = tree.front();
            tree.pop();
            if (node->val > max)
            {
                max = node->val;
            }
            if (node->left)
            {
                tree.push(node->left);
            }
            if (node->right)
            {
                tree.push(node->right);
            }
        }
        return max;
    }
    int min(TreeNode*root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int min = root->val;
        queue<TreeNode*>tree;
        tree.push(root);
        while (1)
        {
            if (tree.empty())
            {
                break;
            }
            auto node = tree.front();
            tree.pop();
            if (node->val < min)
            {
                min = node->val;
            }
            if (node->left)
            {
                tree.push(node->left);
            }
            if (node->right)
            {
                tree.push(node->right);
            }
        }
        return min;
    }
};
