class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
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
}; 