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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getlen(headA);
		int lenB = getlen(headB);
		if (lenA == 0 || lenB == 0)
		{
			return NULL;
		}
		if (lenA < lenB)
		{
			swap(headA, headB);
			swap(lenA, lenB);
		}
		while (lenA > lenB)
		{
			headA = headA->next;
			lenA--;
		}
		while (headA != NULL)
		{
			if (headA == headB)
			{
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
private:
	int getlen(ListNode *head)
	{
		int len = 0;
		while (head != NULL)
		{
			len++;
			head = head->next;
		}
		return len;
	}
};
