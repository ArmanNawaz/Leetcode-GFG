class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        i, currPos, jumps, maxJump = 0, 0, 0, 0
        
        while currPos < n - 1:
            maxJump = max(maxJump, i + nums[i])
            
            if i == currPos:
                currPos = maxJump
                jumps += 1
            i += 1
        return jumps
        
        