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
            return head;
        }
        ListNode header(0);
        auto hheader = &header;
        hheader->next = head;
        auto prev = hheader;
        auto start = head;
        bool flag = false;
        while (start->next != NULL)
        {
            auto node = start->next;
            if (start->val != node->val)
            {
                if (flag == true)
                {
                    prev->next = node;
                    delete start;
                    start = node;
                    flag = false;
                }
                else
                {
                    prev = start;
                    start = node;
                }
            }
            else
            {
                flag = true;
                delete start;
                start = node;
                prev->next = node;
            }
        }
        if (flag == true)
        {
            prev->next = NULL;
            delete start;
        }
        auto node = hheader->next;
        hheader->next = NULL;
        return node;
    }

