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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (11 == NULL && 12 == NULL)
		{
			return NULL;
		}
		if (l1 == NULL)
		{
			return l2;
		}
		if (l2 == NULL)
		{
			return l1;
		}
		auto head = new ListNode(l1->val+l2->val);
		int flag = 0;
		if (head->val >= 10)
		{
			head->val -= 10;
			flag = 1;
		}
		auto ret = head;
		l1 = l1->next;
		l2 = l2->next;
		while (l1 != NULL && l2 != NULL)
		{
			auto node = new ListNode(l1->val + l2->val + flag);
			flag = 0;
			if (node->val >= 10)
			{
				node->val -= 10;
				flag = 1;
			}
			head->next = node;
			head = node;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL)
		{
			auto node = new ListNode(l1->val + flag);
			flag = 0;
			if (node->val >= 10)
			{
				node->val -= 10;
				flag = 1;
			}
			head->next = node;
			head = node;
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			auto node = new ListNode(l2->val + flag);
			flag = 0;
			if (node->val >= 10)
			{
				node->val -= 10;
				flag = 1;
			}
			head->next = node;
			head = node;
			l2 = l2->next;
		}
		if (flag == 1)
		{
			auto node = new ListNode(1);
			head->next = node;
			head = node;
		}
		head->next = NULL;
		return ret;
    }
};
