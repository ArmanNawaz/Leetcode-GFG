class Solution:
    def reverseWords(self, s: str) -> str:
        tmp = s.split()
        result = []
        
        for wrd in tmp:
            result.append(wrd[::-1])
        
        return ' '.join(result)