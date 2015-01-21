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
    ListNode *insertionSortList(ListNode *head) {
       if (head == NULL ||
			head->next == NULL)
		{
			return head;
		}
		auto cur = head->next;
		head->next = NULL;
		auto prev = cur;
		while (cur != NULL)
		{
			prev = cur;
			cur = cur->next;
			head = insetListNode(head, prev);
		}
	}
private:
	ListNode* insetListNode(ListNode *head, ListNode *node)
	{
		if (head == NULL || node == NULL)
		{
			return false;
		}
		if (head->val > node->val)
		{
			node->next = head;
			return node;
		}
		auto prev = head;
		auto cur = head->next;
		while (cur != NULL)
		{
			if (cur->val < node->val)
			{
				prev = cur;
				cur = cur->next;
			}
			else
			{
				prev->next = node;
				node->next = cur;
				return head;
			}
		}
		prev->next = node;
		node->next = NULL;
		return head;
	}
};
