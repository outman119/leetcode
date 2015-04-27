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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
        {
            return head;
        }
        ListNode head1(0);
        head1.next = head;
        auto prev = &head1;
        auto first = head;
        while (first != NULL)
        {
            if (first->val == val)
            {
                prev->next = first->next;
                first = first->next;
            }
            else
            {
                prev = first;
                first = first->next;
            }
        }
        return head1.next;
    }
};
