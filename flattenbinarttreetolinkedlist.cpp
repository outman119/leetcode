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
    void flatten(TreeNode *root) {
        if (root == NULL)
        {
            return;
        }
        stack<TreeNode*> st1;
        st1.push(root);
        auto node = root;
        while (1)
        {
            if (st1.empty())
            {
                break;
            }
            auto tmp = st1.top();
            st1.pop();
            if (tmp->right)
            {
                st1.push(tmp->right);
            }
            if (tmp->left)
            {
                st1.push(tmp->left);
            }
            tmp->left = NULL;
            tmp->right = NULL;
            if (tmp != root)
            {
                node->right = tmp;
                node = tmp;
            }
        }
    }
};
