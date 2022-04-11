class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n = len(grid)
        m = len(grid[0])
        
        ans = [[0] * m for _ in range(n)]
        
        for i in range(n):
            for j in range(m):
                x = (i + (j + k) // m) % n
                y = (j + k) % m
                
                ans[x][y] = grid[i][j]
                
        return ans