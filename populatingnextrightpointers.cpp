/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
        {
            return;
        }
        vector<vector<TreeLinkNode*> > ret;
        queue<TreeLinkNode*>que1;
        que1.push(root);
        TreeLinkNode *index = root;
        vector<TreeLinkNode*>level;
        while (1)
        {
            if (que1.empty())
            {
                break;
            }
            TreeLinkNode *ptr = que1.front();
            level.push_back(ptr);
            if (ptr->left)
            {
                que1.push(ptr->left);
            }
            if (ptr->right)
            {
                que1.push(ptr->right);
            }
            que1.pop();
            if (index == ptr)
            {
                ret.push_back(level);
                level.clear();
                if (!que1.empty())
                {
                    index = que1.back();
                }
            }
        }
        for (unsigned int i = 0; i < ret.size(); i++)
        {
            for (unsigned int j = 0; j < ret[i].size()-1; j++)
            {
                ret[i][j]->next = ret[i][j + 1];          
            }
            ret[i][ret[i].size() - 1]->next = NULL;
        }
        return;
    }
};
