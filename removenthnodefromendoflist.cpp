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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || n == 0)
		 {
			 return head;
		 }
		 ListNode *first = head;
		 ListNode *second = head;
		 while (n > 0 && first != NULL)
		 {
			 first = first->next;
			 n--;
		 }
		 if (n != 0)
		 {
			 return false;
		 }
		 if (first == NULL)
		 {
			 second = head->next;
			 delete head;
			 return second;
		 }
		 while (first->next != NULL)
		 {
			 second = second->next;;
			 first = first->next;
		 }

		 first = second->next->next;
		 delete second->next;
		 second->next = first;
		 return head;
    }
};
