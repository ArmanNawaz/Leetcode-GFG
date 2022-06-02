class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        return daily(nums);
    }
private:
    vector<int> daily(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        return nums;
    }
};