# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if None == node:
            return None
        q = []
        copynode = UndirectedGraphNode(node.label)
        d = {node:copynode}
        q.insert(0,node)
        while 0 != len(q):
            curnode = q.pop()
            for neig in curnode.neighbors:
                if neig not in d:
                    newnode = UndirectedGraphNode(neig.label)
                    d[neig] = newnode
                    d[curnode].neighbors.append(newnode)
                    q.insert(0,neig)
                else:
                    d[curnode].neighbors.append(d[neig])
        return copynode
                    
            
