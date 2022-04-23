class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows <= 1:
            return s
        
        res = [['-'] * 1001 for _ in range(numRows)]
        dr = 1
        i, j = 0, 0
        
        for ch in s:
            res[i][j] = ch
            
            i += dr
            
            if i == numRows:
                i -= 2
                dr *= -1
            
            elif i == -1:
                i += 2
                dr *= -1
            
            if dr == -1:
                j += 1
                
        ans = []
        for row in res:
            for ch in row:
                if ch != '-':
                    ans.append(ch)
        return ''.join(ans)