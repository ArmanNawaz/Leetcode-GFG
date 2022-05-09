class Solution {
public:
    void sortColors(vector<int>& nums) {
        return solve(nums);
    }
private:
    void solve(vector<int>& nums) {
        int low = 0, i = 0, high = nums.size() - 1;
        
        while(low <= high) {
            if(nums[low] == 0) {
                swap(nums[low], nums[i]);
                ++i;
                ++low;
            }
            else if(nums[low] == 2) {
                swap(nums[low], nums[high]);
                --high;
            }
            else
                ++low;
        }
    }
};