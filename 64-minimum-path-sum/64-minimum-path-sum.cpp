class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        // start from (0, 0)
        return dfs(grid, 0, 0, dp);
    }
private:
    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dp) {
        int m = grid.size(); // rows
        int n = grid[0].size(); // columns
        
        // if current coordinates are not feasible
        if(x >= m || y >= n)
            return INT_MAX;
        
        // if we are at last cell, return its value
        if(x == m - 1 && y == n - 1) 
            return dp[x][y] = grid[x][y];
        
        // if current coordinates are already visited, then return its value
        if(dp[x][y] != -1) 
            return dp[x][y];
        
        
        int fromBottom = dfs(grid, x + 1, y, dp); // get result by moving down from current cell
        int fromRight = dfs(grid, x, y + 1, dp); // get result by moving right from current cell
        
        // return min of both plus the current cell value
        return dp[x][y] = grid[x][y] + min(fromBottom, fromRight);
        
    }
    
};