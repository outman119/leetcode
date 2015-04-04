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
    vector<int> rightSideView(TreeNode *root) {
        vector<int>ret;
        if (root == NULL)
        {
            return ret;
        }
        queue<TreeNode*>que;
        que.push(root);
        auto index = root;
        while (1)
        {
            if (que.empty())
            {
                break;
            }
            auto node = que.front();
            que.pop();
            if (node->left)
            {
                que.push(node->left);
            }
            if (node->right)
            {
                que.push(node->right);
            }
            if (node == index)
            {
                ret.push_back(index->val);
                index = que.back();
            }
        }
        return ret;
    }
};
