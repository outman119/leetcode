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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        //sawp first two listnode
        auto node = head->next;
        head->next = node->next;
        node->next = head;
        auto prev = head;
        head = node;
        node = prev->next;
        //then the result
        while (node != NULL && node->next != NULL)
        {
            auto nextnode = node->next;
            prev->next = nextnode;
            node->next = nextnode->next;
            nextnode->next = node;
            prev = node;
            node = node->next;
        }
        return head;
    }

