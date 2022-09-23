class Solution:
    def concatenatedBinary(self, n: int) -> int:
        # daily
        
        ans = []
        
        for i in range(1, n + 1):
            ans.append(bin(i)[2 : ])
        
        ans = ''.join(ans)
        
        return int(ans, 2) % 1000000007
        