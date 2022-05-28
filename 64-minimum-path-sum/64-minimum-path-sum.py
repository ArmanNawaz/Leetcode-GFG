class Solution:
    def dfs(self, grid, x, y, dp):
        m = len(grid)
        n = len(grid[0])
        
        # if current coordinates are not feasible
        if x >= m or y >= n:
            return float('inf')
        
        # if we are at last cell
        if x == m - 1 and y == n - 1:
            dp[x][y] = grid[x][y]
            return dp[x][y]
        
        # if current subproblem is already solved
        if dp[x][y] != -1:
            return dp[x][y]
        
        
        # solve for both two moves - right and down
        fromBottom = self.dfs(grid, x + 1, y, dp)  # solve by moving down
        fromRight = self.dfs(grid, x, y + 1, dp)  # solve by moving right
        
        # store minimum of both plus the current cell value
        dp[x][y] = grid[x][y] + min(fromBottom, fromRight) 
        
        return dp[x][y]
        
        
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp = [[-1] * len(grid[0]) for _ in range(len(grid))]
        return self.dfs(grid, 0, 0, dp)