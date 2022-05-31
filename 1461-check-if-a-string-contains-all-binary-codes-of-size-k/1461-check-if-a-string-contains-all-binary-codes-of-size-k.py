class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n = len(s)
        
        if k > n:
            return False
        
        mySet = set()
        for i in range(n - k + 1):
            mySet.add(s[i: i + k])
            
        return len(mySet) == (1 << k)