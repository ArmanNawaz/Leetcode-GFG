class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        # Rahul sir
        n = len(arr)
        
        dp = [-float('inf') for _ in range(n)]
        dp[0] = arr[0]
        
        for i in range(1, n):
            maxEle = arr[i]
            for j in range(i, max(0, i - k + 1) - 1, -1):
                maxEle = max(maxEle, arr[j])
                winSize = i - j + 1
                
                if j > 0:
                    dp[i] = max(dp[i], maxEle * winSize + dp[j - 1])
                else:
                    dp[i] = max(dp[i], maxEle * winSize)
        
        return dp[n - 1]