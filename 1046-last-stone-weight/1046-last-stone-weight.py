import heapq
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        maxHeap = []
        
        for i in stones:
            heapq.heappush(maxHeap, -i)
        
        while len(maxHeap) > 1:
            y = -heapq.heappop(maxHeap)
            x = -heapq.heappop(maxHeap)
            
            if x != y:
                heapq.heappush(maxHeap, -1 * (y - x))
        
        if len(maxHeap) == 0:
            return 0
        return -maxHeap[0]