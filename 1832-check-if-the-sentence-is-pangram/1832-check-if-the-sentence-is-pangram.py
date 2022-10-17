class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        seen = [False] * 26
        
        for ch in sentence:
            seen[ord(ch) - ord('a')] = True
        
        for x in seen:
            if x == False:
                return False
        
        return True