class Solution:
    def numSquares(self, n: int) -> int:
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        dp[1] = 1
        
        for i in range(2, n + 1):
            j = 1
            while j * j <= i:
                rem = i - j * j
                dp[i] = min(dp[i], dp[rem] + 1)
                j += 1
                
        return dp[-1]