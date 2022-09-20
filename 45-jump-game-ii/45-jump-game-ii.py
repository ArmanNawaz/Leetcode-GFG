class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        
        if n == 1: return 0
        
        jumps = 1
        maxReach = nums[0]
        winEnd = nums[0]
        
        for i in range(1, n - 1):
            maxReach = max(maxReach, i + nums[i])
            if i == winEnd:
                jumps += 1
                winEnd = maxReach
        
        return jumps