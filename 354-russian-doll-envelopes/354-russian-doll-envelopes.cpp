class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    }
 
    int maxEnvelopes(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), comp);

        vector<int> ans;
        ans.push_back(nums[0][1]);
        for(int i = 1; i < n; i++) {
            if(ans.back() < nums[i][1])
                ans.push_back(nums[i][1]);
            else {
                auto it = lower_bound(ans.begin(), ans.end(), nums[i][1]);
                *it = nums[i][1];
            }
        }
        return ans.size();
    }
};