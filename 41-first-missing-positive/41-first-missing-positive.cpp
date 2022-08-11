class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        return bruteForce(nums);
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
            if(nums[i] != (i + 1)) {
                if(nums[i] > 0 and nums[i] < n)
                    swap(nums[i], nums[nums[i]]);
            }
        }
        
        for(int i = 0; i < n; ++i) {
            if(i + 1 != nums[i])
                return i + 1;
        }
        return n + 1;
    }
};