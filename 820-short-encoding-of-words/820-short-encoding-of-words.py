class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        mySet = set(words)
        
        for word in words:
            for i in range(1, len(word)):
                if word[i: ] in mySet:
                    mySet.remove(word[i: ])
                
        ans = 0
        
        for word in mySet:
            ans += len(word) + 1
            
        return ans
        