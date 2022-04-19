class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        
        m, n = len(matrix), len(matrix[0])
        
        rows = [False] * m
        cols = [False] * n
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    rows[i] = True
                    cols[j] = True
        
        for i in range(m):
            if rows[i] == True:
                for j in range(n):
                    matrix[i][j] = 0
        
        for j in range(n):
            if cols[j] == True:
                for i in range(m):
                    matrix[i][j] = 0
            
         