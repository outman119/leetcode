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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
         vector<vector<int>>ret;
        if (root == NULL)
        {
            return ret;
        }
        vector<int>path;
        cal(root, sum, path, ret);
        return ret;
    }
private:
    void cal(TreeNode *root, int sum, vector<int>path, vector<vector<int>>&ret)
    {
        if (root == NULL)
        {
            return;
        }
        path.push_back(root->val);
        if (root->left == NULL &&
            root->right == NULL)
        {
            if (root->val == sum)
            {
                ret.push_back(path);
            }
        }
        int rem = sum - root->val;
        if (root->right)
        {
            cal(root->right, rem, path, ret);
        }
        if (root->left)
        {
            cal(root->left, rem, path, ret);
        }
        return;

    }

};
