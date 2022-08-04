class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # Rahul sir
        
        b1, b2 = 0, 0
        
        for n in nums:
            b1 = (~b2) & (b1 ^ n)
            b2 = (~b1) & (b2 ^ n)
        
        return b1