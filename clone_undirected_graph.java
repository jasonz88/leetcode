/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     ArrayList<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
 
import java.util.concurrent.LinkedBlockingQueue;

public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (null == node) return null;
 
    HashMap<UndirectedGraphNode,UndirectedGraphNode> map = new HashMap<UndirectedGraphNode,UndirectedGraphNode>();
    Queue<UndirectedGraphNode> q = new LinkedBlockingQueue<UndirectedGraphNode>();
    q.add(node);
 
    UndirectedGraphNode graphCopy = new UndirectedGraphNode(node.label);
    map.put(node,graphCopy);
 
    while (!q.isEmpty()) {
        UndirectedGraphNode curnode = q.peek();
        q.remove();
        int n = curnode.neighbors.size();
        for (int i = 0; i < n; ++i) {
            UndirectedGraphNode neighbor = curnode.neighbors.get(i);
            // no copy exists
            if (!map.containsKey(neighbor)) {
                UndirectedGraphNode p = new UndirectedGraphNode(neighbor.label);
                map.get(curnode).neighbors.add(p);
                map.put(neighbor, p);
                //p->neighbors.push_back(map[curnode]);
                q.add(neighbor);
            } else {     // a copy already exists
                map.get(curnode).neighbors.add(map.get(neighbor));
                //map[neighbor]->neighbors.push_back(map[curnode]);
            }
        }
    }
 
    return graphCopy;
        
    }
}
