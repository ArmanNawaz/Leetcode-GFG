class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size() + 1, -1));
        return solve(prices, 0, true, dp);
    }
private:
    int solve(vector<int>& prices, int idx, bool buy, vector<vector<int>>& dp) {
        
        if(dp[buy][idx] != -1) 
            return dp[buy][idx];
        
        if(idx >= prices.size())
            return 0;
        
        int profit1, profit2;
        if(buy) {
            profit1 = solve(prices, idx + 1, !buy, dp) - prices[idx];
            profit2 = solve(prices, idx + 1, buy, dp);
        }
        else{
            profit1 = solve(prices, idx + 1, !buy, dp) + prices[idx];
            profit2 = solve(prices, idx + 1, buy, dp);
        }
        
        return dp[buy][idx] = max(profit1, profit2);
    }
};