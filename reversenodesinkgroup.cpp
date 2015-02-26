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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || k <= 1)
        {
            return head;
        }
        ListNode hh(0);
        hh.next = head;
        auto first = &hh;
        auto second = head;
        auto count = k;
        auto next = head;
        while (second != NULL)
        {
            if (count == 1)
            {
                count = k;
                auto tmp = first->next;
                next = second->next;
                first->next = second;
                first = tmp;
                while (first != second)
                {
                    auto tmp = first->next;
                    first->next = second->next;
                    second->next = first;
                    first = tmp;
                }
                first = tmp;
                second = next;
            }
            else
            {
                second = second->next;
                count--;
            }
        }
        return hh.next;
    }
};
