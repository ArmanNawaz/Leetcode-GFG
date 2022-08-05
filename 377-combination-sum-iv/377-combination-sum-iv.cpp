class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, target);
    }
private:
    int recurse(vector<int>& nums, int idx, int target, vector<vector<int>>& dp) {
        // base case
        if(target < 0) return 0;
        if(target == 0) {
            return 1;
        }
        
        if(dp[idx][target] != -1)
            return dp[idx][target];
        
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            ans += recurse(nums, i, target - nums[i], dp);
        }
        return dp[idx][target] = ans;
    }
    
    int solve(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        recurse(nums, 0, target, dp);
        
//         for(auto x: dp) {
//             for(auto y: x)
//                 cout<<y<<" ";
//             cout<<"\n";
//         }
        
        
        return dp[0][target];
    }
};