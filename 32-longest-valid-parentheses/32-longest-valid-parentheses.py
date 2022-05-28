class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = deque()
        maxLen = 0
        
        stack.append(-1)
        
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if len(stack) == 0:
                    stack.append(i)
                else:
                    maxLen = max(maxLen, i - stack[-1])
        return maxLen