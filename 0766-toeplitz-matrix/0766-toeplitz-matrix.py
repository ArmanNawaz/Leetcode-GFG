class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        m, n = len(matrix), len(matrix[0])
        
        if m == 1 and n == 1: return True
        
        for gap in range(0, n):
            i, j = 0, gap
            top = matrix[i][j]
            
            while i < m and j < n:
                if matrix[i][j] != top:
                    return False
                i += 1
                j += 1
        
        for gap in range(1, m):
            i, j = gap, 0
            top = matrix[i][j]
            
            while i < m and j < n:
                if matrix[i][j] != top:
                    return False
                i += 1
                j += 1
        
        return True
        