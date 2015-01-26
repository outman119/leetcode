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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k <= 0)
        {
            return head;
        }
        int len = getListlen(head);
        if (k%len == 0)
        {
            return head;
        }
        k = k % len;
        auto first = head;
        auto second = head;
        while (k > 0)
        {
            if (first != NULL)
            {
                first = first->next;
                k--;
            }
            else
            {
                return head;
            }
        }
        auto pre1 = first;
        auto pre2 = second;
        while (first != NULL)
        {
            pre1 = first;
            pre2 = second;
            second = second->next;
            first = first->next;
        }
        if (second == head)
        {
            return head;
        }
        pre2->next = NULL;
        pre1->next = head;
        head = second;
        return head;
    }
private:
    int getListlen(ListNode *head)
    {
        if (head == NULL)
        {
            return 0;
        }
        auto node = head;
        int len = 0;
        while (node != NULL)
        {
            node = node->next;
            len++;
        }
        return len;
    }
};
