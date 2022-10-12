class Solution {
    bool canForm(int a, int b, int c) {
        if(a + b <= c) return false;
        if(c + b <= a) return false;
        if(a + c <= b) return false;
        return true;
    }
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        int n = nums.size();
        
        for(int i = 0; i < n - 2; ++i) {
            if(canForm(nums[i], nums[i + 1], nums[i + 2]))
                return nums[i] + nums[i + 1] + nums[i + 2];
        } 
        return 0;
    }
};