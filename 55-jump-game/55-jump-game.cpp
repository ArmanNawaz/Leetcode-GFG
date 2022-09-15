class Solution {
public:
    bool canJump(vector<int>& nums) {
        return solve(nums);
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
};