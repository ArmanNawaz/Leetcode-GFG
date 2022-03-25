class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return solve(nums);
    }
private:
    int solve(vector<int>& nums){
        int n = nums.size();
        int candidate = nums[0];
        int fre = 1;
        for(int j = 1; j < n; ++j){
            if(candidate == nums[j])
                ++fre;
            else
                --fre;
            if(fre == 0 and j != n - 1)
                candidate = nums[j+1];
        }
        
        return candidate;
    }
};