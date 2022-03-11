class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        
        # O(n) Time and O(1) extra space
        wStart, wSum, minSize = 0, 0, len(nums) + 1
        
        for wEnd in range(len(nums)):
            wSum += nums[wEnd]
            
            while wSum >= target:
                wSum -= nums[wStart]
                minSize = min(minSize, wEnd - wStart + 1)
                wStart += 1
        if minSize >= len(nums) + 1:
            return 0
        return minSize