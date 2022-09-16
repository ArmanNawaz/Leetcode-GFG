class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        
        def recurse(idx):
            if len(partialAns) == k:
                ans.append(partialAns[:])
                return
            
            for i in range(idx, n + 1):
                partialAns.append(i)
                recurse(i + 1)
                partialAns.pop()
        
        ans = []
        partialAns = []
        recurse(1)
        
        return ans
        