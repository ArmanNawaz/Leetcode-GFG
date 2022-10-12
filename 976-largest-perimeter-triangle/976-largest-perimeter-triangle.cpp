class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        int n = nums.size();
        
        for(int i = 0; i < n - 2; ++i) {
            if(nums[i] < nums[i + 1] + nums[i + 2])
                return nums[i] + nums[i + 1] + nums[i + 2];
        } 
        return 0;
    }
};