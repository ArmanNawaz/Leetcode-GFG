class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0] * n for _ in range(n)]
        
        r1, r2, c1, c2 = 0, n - 1, 0, n - 1
        value = 1
        
        while r1 <= r2 and c1 <= c2:
            
            # Left -> Right
            for i in range(c1, c2 + 1):
                matrix[r1][i] = value
                value += 1
                
            # Up -> Down
            for i in range(r1 + 1, r2 + 1):
                matrix[i][c2] = value
                value += 1
                
            # Right -> Left
            for i in range(c2 - 1, c1, -1):
                matrix[r2][i] = value
                value += 1
            
            # Down to Up
            for i in range(r2, r1, -1):
                matrix[i][c1] = value
                value += 1
            
            r1 += 1
            r2 -= 1
            c1 += 1
            c2 -= 1
            
        return matrix