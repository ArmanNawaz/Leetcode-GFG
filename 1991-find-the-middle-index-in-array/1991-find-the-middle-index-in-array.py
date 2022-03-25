class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        n = len(nums)
        prefSum = [0] * (n + 1)
        
        prefSum[0] = 0
        
        for i in range(1, n + 1):
            prefSum[i] = prefSum[i - 1] + nums[i - 1]
        
        
        for i in range(1, n + 1):
            if prefSum[i - 1] == prefSum[n] - prefSum[i]:
                return i - 1
        return -1