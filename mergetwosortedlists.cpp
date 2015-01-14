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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
		if (head == NULL)
		{
			return NULL;
		}
		ListNode *tmp = head;
		while (l1 && l2)
		{
			if (l1->val > l2->val)
			{
				tmp->next = l2;
				l2 = l2->next;
				tmp = tmp->next;
			}
			else
			{
				tmp->next = l1;
				l1 = l1->next;
				tmp = tmp->next;
			}
		}
		while (l1)
		{
			tmp->next = l1;
			l1 = l1->next;
			tmp = tmp->next;
		}
		while (l2)
		{
			tmp->next = l2;
			l2 = l2->next;
			tmp = tmp->next;
		}
		tmp->next = NULL;
		tmp = head->next;
		delete head;
		return tmp;
    }
};
