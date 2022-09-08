class Solution:
    def rob(self, nums: List[int]) -> int:
        # Rahul sir 
        # O(n) Time and O(1) extra space
        if len(nums) == 1:
            return nums[0]
        
        def solve(start, end):
            inc = nums[start]
            exc = 0
            
            for i in range(start + 1, end):
                x = inc
                inc = max(inc, exc + nums[i])
                exc = max(exc, x)
            return max(inc, exc)
        
        return max(solve(0, len(nums) - 1), solve(1, len(nums)))
                