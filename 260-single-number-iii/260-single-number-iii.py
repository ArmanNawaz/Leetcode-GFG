class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        # Rahul sir
        bitmask = 0
        
        for n in nums:
            bitmask ^= n
        
        diff = bitmask & -bitmask
        
        a = 0
        
        for n in nums:
            if (n & diff) != 0:
                a ^= n
        
        b = a ^ bitmask
        
        return [a, b]
        
        