class Solution:
    def rob(self, nums: List[int]) -> int:
        # O(n) Time and O(1) extra space
        
        n = len(nums)
        
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums)
        nums[1] = max(nums[0], nums[1])
        
        for i in range(2, n):
            nums[i] = max(nums[i - 1], nums[i] + nums[i - 2])
        
        return nums[-1]
        