class Solution {
public:
    int kInversePairs(int n, int k) {
        return optimised(n, k);
        // vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        // return solve(n, k, dp);
    }
private:
    int solve(int n, int k, vector<vector<int>>& dp) {
        int mod = 1e9 + 7;
        
        if(k <= 0) return k == 0;
        
        if(dp[n][k] != -1)
            return dp[n][k];
        
        dp[n][k] = 0;
        for(int i = 0; i < n; ++i) {
            dp[n][k] = (dp[n][k] + solve(n - 1, k - i, dp)) % mod;
        }
        return dp[n][k];
    }
    
    int optimised(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        int mod = 1e9 + 7;
        
        
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= k; ++j) {
                if(j > 0)
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                else
                    dp[i][j] = dp[i - 1][j] % mod;
                
                if(j >= i)
                    dp[i][j] = (mod + dp[i][j] - dp[i - 1][j - i]) % mod;
            }
        }
        
        return dp[n][k];
    }
   
};