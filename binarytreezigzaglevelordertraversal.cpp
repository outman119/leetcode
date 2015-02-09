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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>>ret;
        if (root == NULL)
        {
            return ret;
        }
        vector<int>level;
        queue<TreeNode*>que;
        que.push(root);
        int k = 1;
        auto index = root;
        while (1)
        {
            if (que.empty())
            {
                break;
            }
            auto node = que.front();
            level.push_back(node->val);
            if (node->left)
            {
                que.push(node->left);
            }
            if (node->right)
            {
                que.push(node->right);
            }
            que.pop();
            if (node == index)
            {
                index = que.back();
                if (k % 2 == 0)
                {
                    reverse(level.begin(), level.end());
                }
                k++;
                ret.push_back(level);
                level.clear();
            }
        }
        return ret;
    }
};
