class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = []
        n = len(strs)
        
        strs.sort()
        
        for i in range(len(strs[0])):
            if strs[0][i] == strs[n - 1][i]:
                ans.append(strs[0][i])
            else:
                break
            
        return "".join(ans)