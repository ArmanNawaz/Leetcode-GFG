class Solution:
    def dfs(self, grid, x, y, visited):
        
        visited[x][y] = True
        
        if x >= 1 and grid[x - 1][y] == '1' and visited[x - 1][y] == False:
            self.dfs(grid, x - 1, y, visited)
            
        if x < len(grid) - 1 and grid[x + 1][y] == '1' and visited[x + 1][y] == False:
            self.dfs(grid, x + 1, y, visited)
            
        if y >= 1 and grid[x][y - 1] == '1' and visited[x][y - 1] == False:
            self.dfs(grid, x, y - 1, visited)
            
        if y < len(grid[0]) - 1 and grid[x][y + 1] == '1' and visited[x][y + 1] == False:
            self.dfs(grid, x, y + 1, visited)
        
    
    def numIslands(self, grid: List[List[str]]) -> int:
        ans = 0
        
        visited = [[False] * len(grid[0]) for _ in range(len(grid))]
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (visited[i][j] == False) and (grid[i][j] == '1'):
                    self.dfs(grid, i, j, visited)
                    ans += 1
        return ans