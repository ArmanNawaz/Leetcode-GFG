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
};