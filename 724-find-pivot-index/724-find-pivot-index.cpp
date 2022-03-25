class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        return solve(nums);
    }
private:
    int solve(vector<int>& nums) {
        vector<int> prefSum(nums.size() + 1, 0);
        
        prefSum[0] = 0;
        int ans = -1;
        int n = nums.size();
        for(int i = 1; i <= n; ++i)
            prefSum[i] = prefSum[i - 1] + nums[i - 1];
        
        // for(auto x: prefSum)
        //     cout<<x<<" ";
        // cout<<endl;
        
        for(int i = 1; i <= n; ++i) {
            if(prefSum[i - 1] == prefSum[n] - prefSum[i])
                return i - 1;
        }
        return -1;
    }
};