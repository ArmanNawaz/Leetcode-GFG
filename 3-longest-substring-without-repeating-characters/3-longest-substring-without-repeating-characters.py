class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        hashMap = dict()
        
        wStart = 0
        maxLength = 0
        
        for wEnd in range(len(s)):
            if s[wEnd] in hashMap:
                wStart = max(wStart, hashMap[s[wEnd]] + 1)
            maxLength = max(maxLength, wEnd - wStart + 1)
            hashMap[s[wEnd]] = wEnd
        return maxLength
            