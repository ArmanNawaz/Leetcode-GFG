class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans = [0] * n
        
        for i in range(n - 1, -1, -1):
            if k-i > 26:
                ans[i] = 'z'
                k = k - 26
            else:
                ans[i] = chr(k - i + 96)
                k = i
            
        return ''.join(ans)