class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        low, high = 0, len(arr) - 1
        mid = 0
        
        while low <= high :        
            mid = low + (high - low) // 2
            
            numberOfMissing = arr[mid] - (mid + 1)
            
            if numberOfMissing < k:
                low = mid + 1
            
            else:
                high = mid - 1
            
        lastMissing = arr[mid] - (mid + 1)
        
        if k > lastMissing:
            return arr[mid] + k - lastMissing
        
        if mid == 0: return k
        
        lastMissing = arr[mid - 1] - mid
        return arr[mid - 1] + k - lastMissing
