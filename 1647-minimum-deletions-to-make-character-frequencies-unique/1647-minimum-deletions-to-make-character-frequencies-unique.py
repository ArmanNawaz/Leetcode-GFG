class Solution:
    def minDeletions(self, s: str) -> int:
        hashMap = dict()
        
        for ch in s:
            hashMap[ch] = hashMap.get(ch, 0) + 1
            
        maxHeap = []
        
        for key, value in hashMap.items():
            heappush(maxHeap, -value)
            
        count = 0
        while len(maxHeap):
            top = -heappop(maxHeap)
            
            if len(maxHeap) > 0 and -maxHeap[0] == top:
                if top != 1:
                    heappush(maxHeap, -(top - 1))
                count += 1
        return count
            