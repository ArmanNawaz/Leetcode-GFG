class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        a, b = 0, 0
        
        for n in arr1:
            a ^= n
        
        for n in arr2:
            b ^= n
        
        return a & b