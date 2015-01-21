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
    ListNode *sortList(ListNode *head) {
        if (head == NULL ||
			head->next == NULL)
		{
			return head;
		}
		auto mid = getMiddle(head);
		auto next = mid->next;
		mid->next = NULL;
		mergeList(sortList(head), sortList(next));

	}
private:
	ListNode *getMiddle(ListNode *head)
	{
		if (head == NULL ||
			head->next == NULL)
		{
			return NULL;
		}
		auto fast = head;
		auto slow = head;
		while (fast->next != NULL &&
			fast->next->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	ListNode* mergeList(ListNode *a, ListNode *b)
	{
		if (a == NULL && b == NULL)
		{
			return NULL;
		}
		auto head = new ListNode(0);
		auto tmp = head;
		while (a != NULL && b != NULL)
		{
			if (a->val > b->val)
			{
				head->next = b;
				head =  head->next;
				b = b->next;
			}
			else
			{
				head->next = a;
				head =  head->next;
				a = a->next;
			}
		}
		if (a != NULL)
		{
			head->next = a;
		}
		if (b != NULL)
		{
			head->next = b;
		}
		auto ret = tmp->next;
		delete tmp;
		return ret;
	}
};
