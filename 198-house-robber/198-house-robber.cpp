class Solution {
public:
    int rob(vector<int>& nums) {
        return solve_tab(nums);
        // vector<int> dp(nums.size(), -1);
        // return solve(nums, 0, dp);
    }
private:
    int solve(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind >= nums.size())
            return 0;        
        
        if(dp[ind] != -1) return dp[ind];
        
        int pick = solve(nums, ind + 2, dp) + nums[ind];
        int notPick = solve(nums, ind + 1, dp);
        
        return dp[ind] = max(pick, notPick);
    }
    
    int solve_tab(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        
        
        for(int i = 1; i < nums.size(); ++i) {
            int take = nums[i];
            if(i >= 2)
                take += dp[i - 2];
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }
        return dp[nums.size() - 1];
    }
}; 