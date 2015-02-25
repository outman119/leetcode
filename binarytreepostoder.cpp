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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int>ret;
        if (root == NULL)
        {
            return ret;
        }
        stack<TreeNode*>st;
        st.push(root);
        auto pre = root;
        while (1)
        {
            if (st.empty())
            {
                break;
            }
            auto node = st.top();
            if ((node->left == NULL && node->right == NULL) ||
                (pre != NULL && (pre == node->left || pre == node->right)))
            {
                ret.push_back(node->val);
                st.pop();
                pre = node;
            }
            else
            {
                if (node->right)
                {
                    st.push(node->right);
                }
                if (node->left)
                {
                    st.push(node->left);
                }
            }
        }
        return ret;
    }
};
