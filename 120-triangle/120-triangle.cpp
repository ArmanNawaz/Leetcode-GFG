class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle);
    }
private:
    int recurse(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        if(i >= triangle.size())
            return 0;
        
        if(i != 0 && dp[i].size() == 1)
            dp[i].resize(triangle[i].size(), -1);
        
        else if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = min(recurse(triangle, i + 1, j, dp), recurse(triangle, i + 1, j + 1, dp)) + triangle[i][j];
    }
    
    int solve(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(1, -1));
        
        return recurse(triangle, 0, 0, dp);
    }
};