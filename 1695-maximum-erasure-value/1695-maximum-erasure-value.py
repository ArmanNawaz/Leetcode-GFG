class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        seen = set()
        winSum, maxSum = 0, 0
        wStart = 0
        
        for wEnd in range(len(nums)):
            while nums[wEnd] in seen:
                seen.remove(nums[wStart])
                winSum -= nums[wStart]
                wStart += 1
            
            winSum += nums[wEnd]
            seen.add(nums[wEnd])
            maxSum = max(maxSum, winSum)
        return maxSum