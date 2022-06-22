class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        minHeap = []
        
        n = len(heights)
        
        for i in range(n - 1):
            diff = heights[i + 1] - heights[i]
            
            if diff > 0:
                heappush(minHeap, diff)
            
            if len(minHeap) > ladders:
                bricks -= heappop(minHeap)
            
            if bricks < 0:
                return i
        return n - 1
            