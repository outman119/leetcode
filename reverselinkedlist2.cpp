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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || m==n)
        {
            return head;
        }
        ListNode node(0);
        auto nw = &node;
        nw->next = head;
        auto first = nw;
        auto second = nw;
        while (m > 1)
        {
            if (first == NULL)
            {
                return head;
            }
            first = first->next;
            m--;
        }
        while (n > 0)
        {
            if (second == NULL)
            {
                return head;
            }
            second = second->next;
            n--;
        }
        if (first == NULL || second == NULL)
        {
            return head;
        }
        reverse(first, second);
        return nw->next;
    }
private:
    ListNode* reverse(ListNode *first, ListNode *second)
    {
        auto head = first;
        first = first->next;
        auto tmp = first->next;
        first->next = second->next;
        second->next = NULL;
        do
        {
            auto node = tmp->next;
            tmp->next = head->next;
            head->next = tmp;
            tmp = node;
        } while (tmp != NULL);
        return head;
    }

