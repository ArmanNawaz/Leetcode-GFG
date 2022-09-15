class Solution {
public:
    bool canJump(vector<int>& nums) {
        return rahulSir(nums);
        // return solve(nums);
    }
private:
    bool solve(vector<int>& nums) {
        int n = nums.size();
        int last = n - 1;
        
        for(int i = n - 2; i >= 0; --i) {
            if(i + nums[i] >= last) last = i;
        }
        
        if(last <= 0) return true;
        return false;
    }
    
    bool rahulSir(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        
        dp[n - 1] = true;
        
        for(int i = n - 2; i >= 0; --i) {
            int farthestJump = min(i + nums[i], n - 1);
            for(int j = i + 1; j <= farthestJump; ++j) {
                if(dp[j] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }    
};