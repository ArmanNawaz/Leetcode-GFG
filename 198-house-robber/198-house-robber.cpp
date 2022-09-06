class Solution {
public:
    int rob(vector<int>& nums) {
        return rahulSir2(nums);
        // return solve_tab(nums);
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
    
    // O(n) Time and O(1) extra space
    int rahulSir(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        nums[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; ++i) {
            nums[i] = max(nums[i - 1], nums[i] + nums[i - 2]);
        }
        
        return nums[n - 1];
    }
    
    // O(n) Time and O(1) extra space
    int rahulSir2(vector<int>& nums) {
        int inc = nums[0];
        int exc = 0;
        
        for(int i = 1; i < nums.size(); ++i) {
            int x = inc;
            inc = exc + nums[i];
            exc = max(x, exc);
        }
        return max(inc, exc);
    }
}; 