class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        # BruteForce
        
        freq = dict()
        
        for x in nums:
            freq[x] = freq.get(x, 0) + 1
        
        ans = []
        
        for key, value in freq.items():
            if value == 1:
                ans.append(key)
        
        return ans