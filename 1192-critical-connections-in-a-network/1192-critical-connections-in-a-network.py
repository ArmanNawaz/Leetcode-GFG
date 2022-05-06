class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        
        
        def dfs(node, parent, graph, timer):
            self.vis[node] = True
            self.dis[node] = timer
            self.low[node] = timer
            timer += 1
            
            for nbr in graph[node]:
                if nbr == parent:
                    continue
                
                elif self.vis[nbr] == False:
                    dfs(nbr, node, graph, timer)
                    self.low[node] = min(self.low[node], self.low[nbr])
                    
                    if self.low[nbr] > self.dis[node]:
                        self.ans.append([node, nbr])
                    
                else:
                    self.low[node] = min(self.low[node], self.dis[nbr])
                                
                        
        
        def buildGraph(edges, n):
            graph = dict()
            
            for i in range(n):
                graph[i] = list()
            
            for edge in edges:
                graph[edge[0]].append(edge[1])
                graph[edge[1]].append(edge[0])
            return graph
        
        self.dis = [0] * n
        self.vis = [False] * n
        self.low = [0] * n
        
        self.ans = list()
        
        graph = buildGraph(connections, n)
        timer = 0
        for node in range(n):
            if self.vis[node] == False:
                dfs(node, -1, graph, timer)
        
        return self.ans
        