class MedianFinder:

    def __init__(self):
        self.minHeap = []
        self.maxHeap = []

    def addNum(self, num: int) -> None:
        if len(self.minHeap) > 0 and num < self.minHeap[0]:
            heappush(self.maxHeap, -num)
        
        else:
            heappush(self.minHeap, num)
        
        diff = len(self.minHeap) - len(self.maxHeap)
        
        if diff > 1:
            heappush(self.maxHeap, -heappop(self.minHeap))
        elif diff < -1:
            heappush(self.minHeap, -heappop(self.maxHeap))

    def findMedian(self) -> float:
        if len(self.minHeap) > len(self.maxHeap):
            return self.minHeap[0]
        
        elif len(self.maxHeap) > len(self.minHeap):
            return -self.maxHeap[0]
    
        else:
            return (self.minHeap[0] - self.maxHeap[0]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()