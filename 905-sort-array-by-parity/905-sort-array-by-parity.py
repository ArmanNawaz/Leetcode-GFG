class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        
        # O(n) Time and O(1) extra space
#         odds = []
#         evens = []
        
#         for n in nums:
#             if n % 2 == 0:
#                 evens.append(n)
#             else:
#                 odds.append(n)
#         i = 0
#         for n in evens:
#             nums[i] = n
#             i += 1
#         for n in odds:
#             nums[i] = n
#             i += 1
#         return nums

        
        # O(n) Time and O(1) extra space
        
        i, j = 0, len(nums) - 1
        
        while i < j:
            while i < len(nums) and nums[i] % 2 == 0: i += 1
            while j >= 0 and nums[j] % 2 != 0: j -= 1
            
            if i < j:
                nums[i], nums[j] = nums[j], nums[i]
        return nums