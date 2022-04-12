class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0 or n == -2147483648:
            return False
        
        n = n & (n - 1)
        
        if n == 0:
            return True
        return False