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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int lenp = preorder.size();
        int leni = inorder.size();
        if (lenp != leni ||
            lenp == 0)
        {
            return NULL;
        }
        queue<TreeNode*>pTree;
        for (int i = 0; i < lenp; i++)
        {
            pTree.push(new TreeNode(preorder[i]));
        }
        return genTree(pTree, inorder, 0, leni - 1);
    }
private:
    TreeNode *genTree(queue<TreeNode*>&pTree, vector<int> &inorder, int start, int end)
    {
        if (pTree.empty())
        {
            return NULL;
        }
        auto root = pTree.front();
        pTree.pop();
        if (pTree.empty())
        {
            return root;
        }
        if (start == end)
        {
            return root;
        }
        int index = find(inorder, start, end, root->val);
        if (index == start)
        {
            root->left = NULL;
            root->right = genTree(pTree, inorder, start +1 , end);
        }
        else if (index == end)
        {
            root->left = genTree(pTree, inorder, start, end - 1);
            root->right = NULL;
        }
        else
        {
            root->left = genTree(pTree, inorder, start, index - 1);
            root->right = genTree(pTree, inorder, index + 1, end);
        }
        return root;
    }
    int find(vector<int>p, int st, int end, int num)
    {
        for (int i = st; i <= end; i++)
        {
            if (p[i] == num)
            {
                return i;
            }
        }
        return end + 1;
    }
};
