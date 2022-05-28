class Solution:
    def longestValidParentheses(self, s: str) -> int:
        op = 0
        cl = 0
        
        ans = 0
        
        for ch in s:
            if ch == '(':
                op += 1
            else:
                cl += 1
                
            if op == cl:
                ans = max(ans, op + cl)
            if op < cl:
                op = 0
                cl = 0
        op, cl = 0, 0
        for i in range(len(s) - 1, -1, -1):
            ch = s[i]
            if ch == '(':
                op += 1
            else:
                cl += 1
                
            if op == cl:
                ans = max(ans, op + cl)
            if op > cl:
                op = 0
                cl = 0
        return ans