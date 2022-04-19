class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        
        low, high = 0, m
        
        # Finding the row of target
        while low < high:
            mid = low + (high - low) // 2
            
            if matrix[mid][0] > target:
                high = mid
            else:
                low = mid + 1
        
        row = low - 1
        low, high = 0, n
        
        # Finding column of target
        while low < high:
            mid = low + (high - low) // 2
            
            if matrix[row][mid] >= target:
                high = mid
            else:
                low = mid + 1
            
        col = low
        
        return (col < n) and (matrix[row][col] == target)