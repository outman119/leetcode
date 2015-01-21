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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *first = head;
        ListNode *next = first->next;
        ListNode *tmp = NULL;
        while (next != NULL)
        {
            if (first->val != next->val)
            {
                first = next;
                next = next->next;
            }
            else
            {
                tmp = next->next;
                first->next = tmp;
                delete next;
                next = tmp;
            }
        }
        return head;
    }
};
