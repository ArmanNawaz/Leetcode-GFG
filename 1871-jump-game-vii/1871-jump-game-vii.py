class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        
        dp = [False] * n
        dp[0] = True
        count = 0
        
        for i in range(1, n):
            if i > maxJump and dp[i - maxJump - 1]:
                count -= 1
            
            if i >= minJump and dp[i - minJump]:
                count += 1
            
            if count > 0 and s[i] == '0':
                dp[i] = True
        
        return dp[n - 1]
                