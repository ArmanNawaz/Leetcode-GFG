class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return 0;
        
        int jumps = 1;
        int maxReach = nums[0];
        int winEnd = nums[0];
        
        for(int i = 1; i < n - 1; ++i) {
            maxReach = max(maxReach, i + nums[i]);
            if(i == winEnd) {
                ++jumps;
                winEnd = maxReach;
            }
        }
        return jumps;
    }
};