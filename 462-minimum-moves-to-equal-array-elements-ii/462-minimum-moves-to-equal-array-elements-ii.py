class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        n = len(nums)
        
        nums.sort()
        req = nums[n // 2]
        
        if n % 2 == 0:
            req = (req + nums[n // 2 - 1]) // 2
        
        ans = 0
        
        for x in nums:
            ans += abs(x - req)
        return ans