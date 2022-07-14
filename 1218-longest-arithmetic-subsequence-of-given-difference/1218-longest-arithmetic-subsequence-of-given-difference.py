class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        hashMap = dict()
        ans = 1
        
        for n in arr:
            hashMap[n] = hashMap.get(n - difference, 0) + 1
            ans = max(ans, hashMap[n])
        return ans
            
        