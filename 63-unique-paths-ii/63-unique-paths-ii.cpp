class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return daily(obstacleGrid);
        // return channaSir(obstacleGrid);
    }
private:
    int solve(int i, int j, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return 1;
        
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i == 0) return dp[i][j] = solve(i, j - 1, dp);
        else if(j == 0) return dp[i][j] = solve(i - 1, j, dp);
        
        else return dp[i][j] = solve(i - 1, j, dp) + solve(i, j - 1, dp);
    }
    int channaSir(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(obstacleGrid[i][j] == 1) dp[i+1][j+1] = 0;
            }
        }        
        return solve(m - 1, n - 1, dp);   
    }
    
    
    // Daily-me
    int recurse(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }
        
        if(obstacleGrid[i][j] == 1)
            return dp[i][j] = 0;
        
        if(i == m - 1 && j == n - 1)
            return dp[i][j] = 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = recurse(obstacleGrid, i + 1, j, dp) + recurse(obstacleGrid, i, j + 1, dp);
    }
    int daily(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        
        return recurse(obstacleGrid, 0, 0, dp);
    }
};