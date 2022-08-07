# a = 1, e = 2, i = 3, o = 4, u = 5
class Solution:
    def recurse(self, ch, count, dp):
        if count == 0:
            return 1
        
        if dp[ch][count] != -1:
            return dp[ch][count]
        
        ans = 0
        mod = 1000000007
        
        if ch == 1:
            ans += self.recurse(2, count - 1, dp)
            ans = ans % mod
        
        elif ch == 2:
            for x in [1, 3]:
                ans += self.recurse(x, count - 1, dp)
                ans = ans % mod
        
        elif ch == 3:
            for x in [1, 2, 4 ,5]:
                ans += self.recurse(x, count - 1, dp)
                ans = ans % mod
        
        elif ch == 4:
            for x in [3, 5]:
                ans += self.recurse(x, count - 1, dp)
                ans = ans % mod
        
        elif ch == 5:
            ans += self.recurse(1, count - 1, dp)
        
        dp[ch][count] = ans
        return ans
        
        
    def countVowelPermutation(self, n: int) -> int:
        dp = [[-1] * n for _ in range(6)]
        ans = 0
        mod = 1000000007
        
        for i in range(1, 6):
            ans += self.recurse(i, n - 1, dp)
            ans = ans % mod
        
        return ans
        
        
        
        
        
        
        
        
        
        