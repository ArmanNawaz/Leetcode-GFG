class Solution:
    def helper(self, s1, s2):
        for ch in s1:
            if ch in s2:
                return False
        return True
        
    def maxProduct(self, words: List[str]) -> int:
        n = len(words)
        
        ans = 0
        s = [set() for _ in range(n)]
        
        for i in range(n):
            for ch in words[i]:
                s[i].add(ch)
            
            for j in range(i):
                if self.helper(s[i], s[j]):
                    ans = max(ans, len(words[i]) * len(words[j]))
        return ans