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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {
            return head;
        }
        auto first = head;
        auto second = head->next;
        head->next = NULL;
        while (second != NULL)
        {
            auto tmp = second->next;
            second->next = first;
            first = second;
            second = tmp;
        }
        return first;
    }
};
