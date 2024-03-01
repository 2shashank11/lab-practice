class Graph:
    def __init__(self, v):
        self.adj=[[] for _ in range(v)]
    
    def addEdge(self, v1, v2, wt):
        self.adj[v1].append([wt, v2])
    
    def ucs(self, v, dist, start, end):
        pq=[]
        dist[start]=0
        pq.append([0, start])
        visited=[0]*v
        visited[start]=1
        traversed=[-1]*v
        while(len(pq)!=0):
            pq.sort()
            parent=pq[0][1]
            weight=pq[0][0]
            pq.pop(0)
            visited[parent]=1

            for wt, node in self.adj[parent]:
                if visited[node]==0:
                    pq.append([dist[parent]+wt, node])
                    if dist[node]>dist[parent]+wt:
                        dist[node]=dist[parent]+wt
                        traversed[node]=parent
        
        print("min-disttt: ", dist[end])

        path=[]
        node=end
        while node!=-1:
            path.append(node)
            node=traversed[node]
        path.reverse()
        print("Path: ", path)

v=7
g=Graph(v)
g.addEdge(0, 1, 2)
g.addEdge(0, 3, 5)
g.addEdge(3, 1, 5)
g.addEdge(1, 6, 1)
g.addEdge(3, 6, 6)
g.addEdge(2, 1, 4)
g.addEdge(6, 4, 7)
g.addEdge(3, 4, 2)
g.addEdge(4, 2, 4)
g.addEdge(5, 2, 6)
g.addEdge(4, 5, 3)
g.addEdge(5, 6, 3)

start=0
end=5
dist=[10**5]*v
g.ucs(v, dist, start, end)
