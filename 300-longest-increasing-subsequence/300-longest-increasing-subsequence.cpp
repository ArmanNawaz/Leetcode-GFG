class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return daily(nums);
    }
private:
    int recurse(vector<int>& nums, int idx, int prev, vector<vector<int>>& dp) {
        if(idx >= nums.size())
            return 0;
        
        if(dp[idx][prev + 1] != -1) return dp[idx][prev + 1];
        
        int len = recurse(nums, idx + 1, prev, dp);
        
        if(prev == -1 || nums[prev] < nums[idx])
            len = max(len, 1 + recurse(nums, idx + 1, idx, dp));
        
        return dp[idx][prev + 1] = len;
    }
    
    int daily(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return recurse(nums, 0, -1, dp);
    }
};