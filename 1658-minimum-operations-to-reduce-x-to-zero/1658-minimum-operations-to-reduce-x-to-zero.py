class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        _sum = sum(nums)
        i, j = 0, 0
        n, ans = len(nums), float('inf')
        
        while i <= j:
            if _sum >= x:
                if _sum == x:
                    ans = min(ans, n + i - j)
                
                if j < n:
                    _sum -= nums[j]
                    j += 1
                else:
                    break
            else:
                _sum += nums[i]
                i += 1
        
        return ans if ans != float('inf') else -1
                    