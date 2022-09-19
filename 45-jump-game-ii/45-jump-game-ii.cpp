class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;
        
        for(int i = n - 2; i >= 0; --i) {
            int maxJump = nums[i];
            
            for(int j = i + 1; j < n && maxJump-- > 0; ++j) {
                if(dp[j] != INT_MAX) {
                    dp[i] = min(dp[j] + 1, dp[i]);
                    // break;
                }
            }
        }
        return dp[0];
    }
};