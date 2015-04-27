/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int len = lists.size();
        if (len == 0)
        {
            return NULL;
        }
        else if (len == 1)
        {
            return lists[0];
        }

        return merge(lists, 0 , len-1);

    }
private:
    ListNode* merge(vector<ListNode *> &lists, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        if (start == end)
        {
            return lists[start];
        }
        int mid = (start + end)/2;
        auto node1 = merge(lists, start, mid);
        auto node2 = merge(lists, mid+1, end);
        return merge(node1, node2);
    }
    ListNode* merge(ListNode *node1, ListNode *node2)
    {
        if (node1 == NULL)
        {
            return node2;
        }
        else if (node2 == NULL)
        {
            return node1;
        }
        ListNode dummy(0);
        auto head = &dummy;
        while (node1 != NULL && node2 != NULL)
        {
            if (node1->val > node2->val)
            {
                head->next = node2;
                node2 = node2->next;
            }
            else
            {
                head->next = node1;
                node1 = node1->next;
            }
            head = head->next;
        }
        while (node1 != NULL)
        {
            head->next = node1;
            node1 = node1->next;
            head = head->next;
        }
        while (node2 != NULL)
        {
            head->next = node2;
            node2 = node2->next;
            head = head->next;
        }
        return dummy.next;
    }
};
