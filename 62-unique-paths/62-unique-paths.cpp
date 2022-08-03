class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return aakashSir(m, n, 0, 0, dp);
        
        return aakashSirTab(m, n);
    }
private:
    int aakashSir(int m, int n, int i, int j, vector<vector<int>>& dp) {
        if(i >= m && j >= n) return 0;
        
        if(i == m - 1 && j == n - 1)
            return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i >= m) return dp[i][j] = aakashSir(m, n, i, j + 1, dp);
        if(j >= n) return dp[i][j] = aakashSir(m, n, i + 1, j, dp);
        
        return dp[i][j] = aakashSir(m, n, i, j + 1, dp) + aakashSir(m, n, i + 1, j, dp);
    }
    
    int aakashSirTab(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; ++i)
            dp[i][0] = 1;
        
        for(int i = 0; i < n; ++i)
            dp[0][i] = 1;
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};