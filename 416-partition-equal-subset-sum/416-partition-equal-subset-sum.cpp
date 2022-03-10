class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum & 1) == 1) return false;
        return solve(nums, nums.size(), sum/2);
    }
private:
    bool solve(vector<int> nums, int n, int k){
        vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
        
        for(int i = 0; i <= n; ++i)
            dp[i][0] = true;
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= k; ++j) {
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][k];
    }
};