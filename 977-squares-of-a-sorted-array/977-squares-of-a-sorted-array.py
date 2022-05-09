class Solution:
    # O(nlogn) Time and O(1) Extra space
    def bruteForce(self, nums):
        for i in range(len(nums)):
            nums[i] = nums[i] * nums[i]
        nums.sort()
        return nums    
    
    # O(n) Time and O(n) extra Space
    def optimised(self, nums):
        result = []
        
        i, j = 0, len(nums) - 1
        
        while i <= j:
            if abs(nums[i]) > abs(nums[j]):
                result.append(nums[i] * nums[i])
                i += 1
            else:
                result.append(nums[j] * nums[j])
                j -= 1
        
        return reversed(result)
    
    def sortedSquares(self, nums: List[int]) -> List[int]:
        # return self.bruteForce(nums)    
        return self.optimised(nums)