class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        arrSum = sum(nums)
        n = len(nums)
        
        nSum = n * (n + 1) // 2
        
        return nSum - arrSum