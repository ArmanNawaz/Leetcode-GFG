class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        
        def solve(arr, n, k):
            dp = [[False]*(k+1) for _ in range(n+1)]
            
            for i in range(n+1):
                dp[i][0] = True
                
            for i in range(1, n+1):
                for j in range(1, k+1):
                    if arr[i-1] > j:
                        dp[i][j] = dp[i-1][j]
                    else:
                        dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]]
            return dp[n][k] 
        
        add = sum(nums)
        if (add & 1) == 1: return False
        return solve(nums, len(nums), add//2)