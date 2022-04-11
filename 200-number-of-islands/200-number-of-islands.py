class Solution:
    def dfs(self, grid, x, y):
        grid[x][y] = '0'
        
        if x >= 1 and grid[x - 1][y] == '1':
            self.dfs(grid, x - 1, y)
            
        if x < len(grid) - 1 and grid[x + 1][y] == '1':
            self.dfs(grid, x + 1, y)
            
        if y >= 1 and grid[x][y - 1] == '1':
            self.dfs(grid, x, y - 1)
            
        if y < len(grid[0]) - 1 and grid[x][y + 1] == '1':
            self.dfs(grid, x, y + 1)
        
    
    def numIslands(self, grid: List[List[str]]) -> int:
        ans = 0
        
        # visited = [[False] * len(grid[0]) for _ in range(len(grid))]
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j)
                    ans += 1
        return ans