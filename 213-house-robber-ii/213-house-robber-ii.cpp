class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
//         vector<int> dp1(n, -1);
//         vector<int> dp2(n, -1);
//         return max(solve(nums, 0, n-2, dp1), solve(nums, 1, n-1, dp2));
        
        return max(rahulSir(nums, 0, n - 1), rahulSir(nums, 1, n));
    }
private:
    int solve(vector<int>& nums, int start, int end, vector<int>& dp) {
        if(end < start) return 0;
        
        if(dp[end] != -1) return dp[end];
        
        dp[end] = max(solve(nums, start, end-2, dp) + nums[end], solve(nums, start, end-1, dp));
        return dp[end];
    }
    
    // O(n) Time and O(1) extra space
    int rahulSir(vector<int>& nums, int start, int end) {
        int inc = nums[start];
        int exc = 0;
        
        for(int i = start + 1; i < end; ++i) {
            int x = inc;
            inc = exc + nums[i];
            exc = max(x, exc);
        }
        return max(inc, exc);
    }
    
};