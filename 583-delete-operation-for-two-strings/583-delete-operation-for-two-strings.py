class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        def lcs_dp_tab(str1, str2, m, n):
            dp = [[0]*(m+1) for _ in range(n+1)]

            for i in range(1, n+1):
                for j in range(1, m+1):
                    if str1[j-1] == str2[i-1]:
                        dp[i][j] = 1 + dp[i-1][j-1]
                    else:
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1])

            return dp[n][m]
        
        m = len(word1)
        n = len(word2)
        
        return m + n - 2 * lcs_dp_tab(word1, word2, m, n)
        