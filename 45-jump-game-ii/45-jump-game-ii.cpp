class Solution {
public:
    int jump(vector<int>& nums) {
        return solve(nums);
    }
private:
    int solve(vector<int>& nums) {
        int n = nums.size();
        int maxJump = 0, currPos = 0, jumps = 0;
        int i = 0;
        
        while(currPos < n - 1) {
            maxJump = max(maxJump, i + nums[i]);
            if(i == currPos) {
                currPos = maxJump;
                ++jumps;
            }
            ++i;
        }
        return jumps;
    }
};