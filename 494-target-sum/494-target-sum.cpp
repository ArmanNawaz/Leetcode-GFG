class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target);
    }
private:
    int recurse(vector<int>& nums, int target, int idx) {
        if(idx == nums.size()) {
            if(target == 0)
                return 1;
            return 0;
        }
        
        return recurse(nums, target - nums[idx], idx + 1) + recurse(nums, target + nums[idx], idx + 1);
        
    }
    
    int solve(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            if(abs(target) == abs(nums[0]))
                return 1;
            return 0;
        }
        
        return recurse(nums, target - nums[0], 1) + recurse(nums, target + nums[0], 1);
    }
};