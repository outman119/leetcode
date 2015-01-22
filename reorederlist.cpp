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
    void reorderList(ListNode *head) {
        if (head == NULL)
        {
            return;
        }
        auto mid = getMiddle(head);
        auto node = mid->next;
        mid->next = NULL;
        node = reverse(node);
        head = merge(head, node);
        return;
    }
private:
    ListNode* getMiddle(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        auto fast = head;
        auto slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        auto curr = head->next;
        auto post = curr;
        auto node = head;
        head->next = NULL;
        while (curr != NULL)
        {
            post = curr->next;
            curr->next = node;
            node = curr;
            curr = post;
        }
        return node;
    }
    ListNode* merge(ListNode *head, ListNode *node)
    {
        if (head == NULL && node == NULL)
        {
            return NULL;
        }
        auto index = head;
        auto prev = head;
        while (head != NULL && node != NULL)
        {
            auto post1 = head->next;
            auto post2 = node->next;
            head->next = node;
            node->next = post1;
            prev = node;
            head = post1;
            node = post2;
        }
        if (node != NULL)
        {
            prev->next = node;
        }
        return index;
    }
};
