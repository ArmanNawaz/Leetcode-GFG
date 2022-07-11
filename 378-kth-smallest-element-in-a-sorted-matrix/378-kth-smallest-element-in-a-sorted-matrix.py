class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        merged = []
        
        for row in matrix:
            merged.extend(row)
        
        merged.sort()
        
        return merged[k - 1]