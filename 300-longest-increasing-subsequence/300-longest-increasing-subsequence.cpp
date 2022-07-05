class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return solve(nums, 0, -1, dp);
    }
private:
    int solve(vector<int>& nums, int ind, int prev, vector<vector<int>>& dp) {
        if(ind >= nums.size())
            return 0;
        
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        
        int len = solve(nums, ind + 1, prev, dp);    // not-take
        
        if(prev == -1 || nums[ind] > nums[prev])
            len = max(len, 1 + solve(nums, ind + 1, ind, dp));
        
        return dp[ind][prev + 1] = len;
    }
};