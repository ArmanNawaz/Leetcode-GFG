class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        return solve(nums);
    }
private:
    // Channa Sir
    // O(n logn)
    void solve(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        while(i >= 0 && nums[i] >= nums[i + 1])
            --i;
        
        if(i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = i + 1;
        
        while(j < n && nums[j] > nums[i])
            ++j;
        --j;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};