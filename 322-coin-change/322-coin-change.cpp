class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        
        int ans = solve(coins, amount, n - 1, dp);
        
        if(ans >= INT_MAX - 1)
            return -1;
        return ans;
    }
private:
    int solve(vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if(amount == 0)
            return 0;
        
        if(amount < 0 || n < 0)
            return INT_MAX - 1;
        
        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        int notPick = solve(coins, amount, n-1, dp);
        
        int pick = INT_MAX;
        
        if(coins[n] <= amount)
            pick = 1 + solve(coins, amount - coins[n], n, dp);
        
        dp[n][amount] = min(pick, notPick);
        
        return dp[n][amount];
    }
};