/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
        {
            return NULL;
        }
        vector<TreeNode*>node;
        while (head != NULL)
        {
            node.push_back(new TreeNode(head->val));
            head = head->next;
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
