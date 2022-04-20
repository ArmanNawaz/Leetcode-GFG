class Solution:
    def buildGraph(self, n, times):
        weight = [[-1] * (n + 1) for _ in range(n + 1)]
        
        for time in times:
            src, dest, wt = time
            weight[src][dest] = wt
            
        return weight
            
    
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        weight = self.buildGraph(n, times)
        
        distance = [float('inf')] * (n + 1)
        visited = [False] * (n + 1)
        
        minHeap = []
        heappush(minHeap, (0, k)) # (cost, node) __ k = source node
        distance[k] = 0
        
        while minHeap:
            currDist, currNode = heappop(minHeap)
            
            if visited[currNode] == False:
                visited[currNode] = True
                
                for vertex in range(1, n + 1):
                    if weight[currNode][vertex] != -1:
                        if currDist + weight[currNode][vertex] < distance[vertex]:
                            distance[vertex] = currDist + weight[currNode][vertex]
                            heappush(minHeap, (distance[vertex], vertex))
        
        ans = max(distance[1: ])
        return -1 if ans == float('inf') else ans
            
        
        