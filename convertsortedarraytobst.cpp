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
    TreeNode *sortedArrayToBST(vector<int> &num) {
       if (num.size() == 0)
        {
            return NULL;
        }
        vector<TreeNode*>node;
        for (unsigned int i = 0; i < num.size(); i++)
        {
            node.push_back(new TreeNode(num[i]));
        }
        return genTree(node, 0, node.size() - 1);
    }
private:
    TreeNode *genTree(vector<TreeNode*>&node, int start, int end)
    {
        if (node.size() < 1)
        {
            return NULL;
        }
        if (start == end)
        {
            return node[start];
        }
        else if (start + 1 == end)
        {
            node[start]->right = node[end];
            return node[start];
        }
        int mid = (start + end) / 2;
        auto root = node[mid];
        root->left = genTree(node, start, mid - 1);
        root->right = genTree(node, mid + 1, end);
        return root;
    }
};
