class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        ans = 0
        maxValue = 0
        
        for i in range(len(arr)):
            maxValue = max(maxValue, arr[i])
            if maxValue == i:
                ans += 1
                
        return ans