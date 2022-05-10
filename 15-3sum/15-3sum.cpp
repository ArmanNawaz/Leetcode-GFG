class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return solve(nums);
    }
private:
    vector<vector<int>> solve(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        int i = 0;
        
        while(i < n) {
            int j = i + 1, k = n - 1;
            
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum < 0)
                    ++j;
                else if(sum > 0)
                    --k;
                else{
                    result.push_back({nums[i], nums[j], nums[k]});
                    int pre = nums[j], nxt = nums[k];
                    while(j < n && k > i && pre == nums[j] && nxt == nums[k]) {
                        ++j;
                        --k;
                    }
                }
            }
            int tmp = nums[i];
            while(i < n && tmp == nums[i])
                ++i;
        }
        return result;
    }
};