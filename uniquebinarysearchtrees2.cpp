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
    vector<TreeNode *> generateTrees(int n) {
            return genTree(1, n);
    }
private:
    vector<TreeNode*> genTree(int begin, int end)
    {
        vector<TreeNode*>ret;
        if (begin > end)
        {
            ret.push_back(NULL);
            return ret;
        }
        for (int i = begin; i <= end; i++)
        {
            auto leftTree = genTree(begin, i - 1);
            auto rightTree = genTree(i+1, end);
            for (unsigned int j = 0; j < leftTree.size(); j++)
            {
                for (unsigned int k = 0; k < rightTree.size(); k++)
                {
                    TreeNode* root = new TreeNode(i);
                    root-> left = leftTree[j];
                    root->right = rightTree[k];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};
