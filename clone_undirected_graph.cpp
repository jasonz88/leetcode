/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
typedef unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> Map;
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return NULL;
 
    Map map;
    queue<UndirectedGraphNode *> q;
    q.push(node);
 
    UndirectedGraphNode *graphCopy = new UndirectedGraphNode(node->label);
    map[node] = graphCopy;
 
    while (!q.empty()) {
        UndirectedGraphNode *curnode = q.front();
        q.pop();
        int n = curnode->neighbors.size();
        for (int i = 0; i < n; ++i) {
            UndirectedGraphNode *neighbor = curnode->neighbors[i];
            // no copy exists
            if (map.find(neighbor) == map.end()) {
                UndirectedGraphNode *p = new UndirectedGraphNode(neighbor->label);
                map[curnode]->neighbors.push_back(p);
                map[neighbor] = p;
                //p->neighbors.push_back(map[curnode]);
                q.push(neighbor);
            } else {     // a copy already exists
                map[curnode]->neighbors.push_back(map[neighbor]);
                //map[neighbor]->neighbors.push_back(map[curnode]);
            }
        }
    }
 
    return graphCopy;
        
    }
};
