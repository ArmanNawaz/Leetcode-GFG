class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        maxHeap = []
        dp = [0] * len(nums)
        
        dp[0] = nums[0]
        heappush(maxHeap, (-nums[0], 0))
        
        for i in range(1, len(nums)):
            while maxHeap[0][1] < i - k:
                heappop(maxHeap)
            
            dp[i] = nums[i] + dp[maxHeap[0][1]]
            
            heappush(maxHeap, (-dp[i], i))
        
        return dp[-1]