class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        return solve(nums);
    }
private:
    int solve(vector<int>& nums) {
        int ans = 0;
        int ones = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 1) {
                ++ones;
                ans = max(ans, ones);
            }
            else
                ones = 0;
        }
        return ans;
    }
};