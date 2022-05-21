class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return daily(coins, amount);
    }
private:
    int recurse(vector<int>& coins, int idx, int amount, vector<vector<int>>& dp) {
        if(idx >= coins.size() || amount <= 0) {
            if(amount == 0)
                return 0;
            return INT_MAX - 1;
        }
        
        if(dp[amount][idx] != -1)
            return dp[amount][idx];
        
        int notPick = recurse(coins, idx + 1, amount, dp);
        int pick = recurse(coins, idx, amount - coins[idx], dp) + 1;
        
        return dp[amount][idx] = min(pick, notPick);
    }
    int daily(vector<int>& coins, int amount) {
        int count = 0;
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, -1));
        int ans = recurse(coins, 0, amount, dp);
        return ans != (INT_MAX - 1) ? ans : -1;
    }
};