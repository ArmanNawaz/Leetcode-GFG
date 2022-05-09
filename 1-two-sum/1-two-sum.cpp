class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return solve(nums, target);
    }
private:
    vector<int> solve(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            int req = target - nums[i];
            if(hashMap.find(req) != hashMap.end())
                return {hashMap[req], i};
            
            hashMap[nums[i]] = i;
        }
        return {};
    }
};