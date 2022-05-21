class Solution:
    def recurse(self, coins, idx, amount, dp):
        if idx >= len(coins) or amount <= 0:
            if amount == 0:
                return 0
            return float('inf')
        
        if dp[amount][idx] != -1:
            return dp[amount][idx]
        
        pick = self.recurse(coins, idx, amount - coins[idx], dp) + 1
        notPick = self.recurse(coins, idx + 1, amount, dp)
        
        dp[amount][idx] = min(pick, notPick)
        
        return dp[amount][idx]
        
        
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [[-1] * (len(coins) + 1) for _ in range(amount + 1)]
        
        ans = self.recurse(coins, 0, amount, dp)
        
        return ans if ans < float('inf') else -1