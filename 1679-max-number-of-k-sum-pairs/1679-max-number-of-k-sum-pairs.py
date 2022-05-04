class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        freq = dict()
        ans = 0
        
        for cur in nums:
            if freq.get(k - cur, 0) > 0:
                ans += 1
                freq[k - cur] -= 1
            else:
                freq[cur] = freq.get(cur, 0) + 1
        return ans