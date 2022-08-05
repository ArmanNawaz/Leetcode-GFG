class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, target);
    }
private:
    int recurse(vector<int>& nums, int target, vector<int>& dp) {
        // base case
        if(target < 0) return 0;
        if(target == 0) {
            return 1;
        }
        
        if(dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            ans += recurse(nums, target - nums[i], dp);
        }
        return dp[target] = ans;
    }
    
    int solve(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        recurse(nums, target, dp);        
        
        return dp[target];
    }
};