class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        return solve(nums);
        // return bruteForce(nums);
    }
private:
    int bruteForce(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen(nums.begin(), nums.end());
        
        for(int i = 1; i <= n; ++i)
            if(seen.find(i) == seen.end())
                return i;
        
        return n + 1;
    }
    
    int solve(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            while(nums[i] != (i + 1) && nums[i] > 0 && nums[i] <= n) {
                if(nums[i] == nums[nums[i] - 1]) break;
            
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for(int i = 0; i < n; ++i) {
            if(i + 1 != nums[i])
                return i + 1;
        }
        return n + 1;
    }
};