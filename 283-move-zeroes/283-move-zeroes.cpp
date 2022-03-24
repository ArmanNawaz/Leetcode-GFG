class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i;
        for(i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0)
                break;
        }
        int j = i + 1;
        
        while(j < nums.size()) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                ++i;
            }
            ++j;            
        }
    }
};