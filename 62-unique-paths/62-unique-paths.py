class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        def memoize(i, j, dp):
            if dp[i][j] != -1:
                return dp[i][j]
            
            if i == 0 and j == 0:
                return 1
            
            dp[i][j] = 0
            
            if i == 0: dp[i][j] = memoize(i, j - 1, dp)
            elif j == 0: dp[i][j] = memoize(i - 1, j, dp)
            else:
                dp[i][j] = memoize(i, j - 1, dp) + memoize(i - 1, j, dp)
            
            return dp[i][j]
            
        dp = [[-1] * n for _ in range(m)]
        return memoize(m - 1, n - 1, dp)