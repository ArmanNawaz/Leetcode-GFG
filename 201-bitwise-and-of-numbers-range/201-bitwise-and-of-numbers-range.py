class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        shiftCount = 0
        
        while left != right and left != 0:
            left = left >> 1
            right = right >> 1
            shiftCount += 1
        
        return left << shiftCount