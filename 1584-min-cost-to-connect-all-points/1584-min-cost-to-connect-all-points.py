class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        i, ans, cp = 0, 0, 1 # cp- connected points
        visited = [False] * n
        minHeap = []
        
        while cp < n:
            visited[i] = True
            
            for j in range(n):
                if not visited[j]:
                    dist = abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0])
                    heappush(minHeap, (dist, j))
                
            
            while visited[minHeap[0][1]]:
                heappop(minHeap)
                
            ans += minHeap[0][0]
            i = minHeap[0][1]
            heappop(minHeap)
            
            cp += 1
            
        return ans
    