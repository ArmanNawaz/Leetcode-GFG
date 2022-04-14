class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        low, high = 1, num // 2
        
        while low < high:
            mid = low + (high - low) // 2
            
            if mid * mid >= num:
                high = mid
            else:
                low = mid + 1
                
        return low * low == num