class Solution:
    def anant(self, coins, idx, target, summ, dp):
        
        if idx >= len(coins) or summ >= target:
            if summ == target:
                return 0
            return float('inf')
        
        if dp[idx][summ] != -1:
            return dp[idx][summ]
        
        
        summ += coins[idx] 
        pick = self.anant(coins, idx, target, summ, dp) + 1
        summ -= coins[idx]
        notPick = self.anant(coins, idx + 1, target, summ, dp)
        
        dp[idx][summ] = min(pick, notPick)
        return dp[idx][summ]
        
        
        
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [[-1] * (amount + 1) for _ in range(len(coins) + 1)]
        ans = self.anant(coins, 0, amount, 0, dp)
        
        return ans if ans != float('inf') else -1