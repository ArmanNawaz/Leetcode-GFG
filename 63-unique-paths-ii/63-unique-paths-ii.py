class Solution:
    def recurse(self, obstacleGrid, i, j, dp):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        
        if i >= m or j >= n:
            return 0
        
        if dp[i][j] != -1:
            return dp[i][j]
        
        if obstacleGrid[i][j] == 1:
            dp[i][j] = 0
            
        elif i == m - 1 and j == n - 1:
            dp[i][j] = 1
        
        else:
            dp[i][j] = self.recurse(obstacleGrid, i + 1, j, dp) + self.recurse(obstacleGrid, i, j + 1, dp)
        
        return dp[i][j]
        
        
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        dp = [[-1] * len(obstacleGrid[0]) for _ in range(len(obstacleGrid))]
        
        return self.recurse(obstacleGrid, 0, 0, dp)