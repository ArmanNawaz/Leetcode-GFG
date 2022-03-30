class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return solve(nums, target);
    }
private:
    vector<vector<int>> solve(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> mySet;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                int newTarget = target - (nums[i] + nums[j]);
                
                int p = j + 1, q = n - 1;
                
                while(p < q) {
                    int sum = nums[p] + nums[q];
                    
                    if(sum < newTarget) ++p;
                    else if(sum > newTarget) --q;
                    else{
                        mySet.insert({nums[i], nums[j], nums[p], nums[q]});
                        ++p;
                        --q;
                    }
                
                }
            }
        }
        vector<vector<int>> ans;
        for(auto value: mySet)
            ans.push_back(value);
        
        return ans;
    }
};