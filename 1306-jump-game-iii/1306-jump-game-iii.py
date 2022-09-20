class Solution:
    
    def recurse(self, arr, idx):
        if idx < 0 or idx >= len(arr): return False
        
        if arr[idx] < 0: return False
        if arr[idx] == 0: return True
        
        arr[idx] = -arr[idx]
        
        return self.recurse(arr, idx - arr[idx]) or self.recurse(arr, idx + arr[idx])
        
        
    
    def canReach(self, arr: List[int], start: int) -> bool:
        return self.recurse(arr, start)