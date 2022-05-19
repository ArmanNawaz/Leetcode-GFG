class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        return solve(matrix);
    }
private:
    bool isValid(int i, int j, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        return true;
    }
    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dp) {
        int m = matrix.size(), n = matrix[0].size();
        
        if(dp[x][y] != -1)
            return dp[x][y];
        
        int ans = 0;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for(int i = 0; i < 4; ++i) {
            int a = x + dir[i].first;
            int b = y + dir[i].second;
            if(isValid(a, b, m, n) && matrix[a][b] > matrix[x][y])
                ans = max(ans, dfs(matrix, x + dir[i].first, y + dir[i].second, dp));
        }
        return dp[x][y] = ans + 1;
    }   
        
    int solve(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, i, j, dp));
            }
        } 
        return ans;
    }
};