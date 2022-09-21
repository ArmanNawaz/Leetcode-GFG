class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        ans = []
        
        evenSum = 0
        
        for x in nums:
            if (x & 1) == 0:
                evenSum += x
        
        for query in queries:
            val, index = query
            
            initialValue = nums[index]
            nums[index] += val
            updatedValue = nums[index]
            
            if (initialValue & 1) == 0:
                evenSum -= initialValue
            
            if (updatedValue & 1) == 0:
                evenSum += updatedValue
            
            ans.append(evenSum)
            
        return ans