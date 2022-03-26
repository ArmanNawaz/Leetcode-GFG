class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return solve(nums);
    }
private:
    int solve(vector<int>& nums){
        int i = 0, j = 1;
        int n = nums.size();
        int res = 0;
        while(j < n){
            if(nums[i] == nums[j]) ++j;
            else{
                ++i;
                nums[i] = nums[j];
                ++res;
            }
        }
        return res+1;
    }
};