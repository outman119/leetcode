/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
        {
            return NULL;
        }
        map<int, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*>q;
        q.push(node);
        while (!q.empty())
        {
            auto tmp = q.front();
            q.pop();

            if (m.count(tmp->label) == 0)
            {
                auto newnode = new UndirectedGraphNode(tmp->label);
                m[tmp->label] = newnode;
            }
            for (unsigned int i = 0; i < tmp->neighbors.size(); i++)
            {
                auto nbors = tmp->neighbors[i];
                if (m.count(nbors->label) == 0)
                {
                    auto nbnode = new UndirectedGraphNode(nbors->label);
                    m[nbors->label] = nbnode; 
                    q.push(nbors);
                }
                m[tmp->label]->neighbors.push_back(m[nbors->label]);
            }
        }
        return m[node->label];
    }
};
