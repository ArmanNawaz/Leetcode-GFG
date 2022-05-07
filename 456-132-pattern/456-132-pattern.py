class Solution:
    # O(n^3) Time and O(1) Space - TLE
    def __bruteForce(self, nums):
        n = len(nums)
        
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                for k in range(j + 1, n):
                    if nums[i] < nums[k] < nums[j]:
                        return True
        return False
    
    # O(n^2) Time and O(1) Space - TLE
    def __solve(self, nums):
        n = len(nums)
        
        minElement = float('inf')
        
        for j in range(n):
            minElement = min(minElement, nums[j])
            
            if minElement == nums[j]:
                continue
            
            for k in range(n - 1, j, -1):
                if minElement < nums[k] < nums[j]:
                    return True
        return False
    
    # O(n) Time and O(1) Space
    def __optimised(self, nums):
        n = len(nums)
        top, thirdElement = n, -float('inf')
        
        for i in range(n - 1, -1, -1):
            if thirdElement > nums[i]:
                return True
            
            while top < n and nums[i] > nums[top]:
                thirdElement = nums[top]
                top += 1
            top -= 1
            nums[top] = nums[i]
        return False
        
    def find132pattern(self, nums: List[int]) -> bool:
        return self.__optimised(nums)
        # return self.__solve(nums)
        # return self.__bruteForce(nums)
    
    
    
    
    
    
    