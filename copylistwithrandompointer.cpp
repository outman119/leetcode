/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
        {
            return NULL;
        }
        map<RandomListNode*, RandomListNode*> m;
        queue<RandomListNode*>q;
        q.push(head);
        while (!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            if (m.count(tmp) == 0)
            {
                auto newnode = new RandomListNode(tmp->label);
                m[tmp] = newnode;
            }
            auto nextnode = tmp->next;
            if (nextnode != NULL)
            {
                if (m.count(nextnode) == 0)
                {
                    auto nn = new RandomListNode(nextnode->label);
                    m[nextnode] = nn;
                    q.push(nextnode);
                }
                
                m[tmp]->next = m[nextnode];
            }
            auto rannode = tmp->random;
            if (rannode != NULL)
            {
                if (m.count(rannode) == 0)
                {
                    auto nn = new RandomListNode(rannode->label);
                    m[rannode] = nn;
                    q.push(rannode);
                }
                
                m[tmp]->random = m[rannode];
            }
        }
        return m[head];
    }
};
