class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashMap = dict()
        
        for word in strs:
            sortedWord = ''.join(sorted(word))
            
            if sortedWord not in hashMap:
                hashMap[sortedWord] = list()
            
            hashMap[sortedWord].append(word)
        
        ans = []
        for key, value in hashMap.items():
            ans.append(value)
        return ans