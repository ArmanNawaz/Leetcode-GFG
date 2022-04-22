class Solution:
    def buildGraph(self, n, flights):
        graph = [[-1] * n for _ in range(n)]
        
        for edge in flights:
            src, dest, cost = edge
            graph[src][dest] = cost
        
        return graph
    
    
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        
        graph = self.buildGraph(n, flights)
        
        stops = [0] * n
        distance = [float('inf')] * n
        
        distance[src] = 0
        minHeap = []
        heappush(minHeap, [distance[src], stops[src], src])
        
        while minHeap:
            dist, stop, currNode = heappop(minHeap)
            
            if currNode == dst:
                return dist
            
            if stop > k:
                continue
            
            for vertex in range(n):
                if graph[currNode][vertex] != -1:
                    nextDist = graph[currNode][vertex] + dist
                    nextStop = stop + 1
                    
                    
                    if nextDist < distance[vertex]:
                        distance[vertex] = nextDist
                        stops[vertex] = nextStop
                        heappush(minHeap, [nextDist, nextStop, vertex])
                    
                    elif nextStop < stops[vertex]:
                        heappush(minHeap, [nextDist, nextStop, vertex])
                        
                    
                        
        return -1
            
            