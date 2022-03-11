class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        
        # O(n) Time and O(1) extra space
        odds = []
        evens = []
        
        for n in nums:
            if n % 2 == 0:
                evens.append(n)
            else:
                odds.append(n)
        i = 0
        for n in evens:
            nums[i] = n
            i += 1
        for n in odds:
            nums[i] = n
            i += 1
        return nums