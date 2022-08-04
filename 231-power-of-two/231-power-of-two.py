class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        # Rahul sir
        return (n != 0) and (n != -2147483648) and ((n & -n) == n)