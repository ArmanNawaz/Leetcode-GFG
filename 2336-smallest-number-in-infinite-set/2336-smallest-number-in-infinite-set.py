class SmallestInfiniteSet:

    def __init__(self):
        self.minHeap = []
        self.mySet = set()
        
        for i in range(1, 1001):
            heappush(self.minHeap, i)
            self.mySet.add(i)
        
    def popSmallest(self) -> int:
        x = heappop(self.minHeap)
        self.mySet.remove(x)
        return x
        
    def addBack(self, num: int) -> None:
        if num not in self.mySet:
            self.mySet.add(num)
            heappush(self.minHeap, num)
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)