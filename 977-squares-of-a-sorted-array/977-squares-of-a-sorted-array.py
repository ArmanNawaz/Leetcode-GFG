class Solution:
    def bruteForce(self, nums):
        for i in range(len(nums)):
            nums[i] = nums[i] * nums[i]
        nums.sort()
        return nums    
    
    
    def sortedSquares(self, nums: List[int]) -> List[int]:
        return self.bruteForce(nums)    