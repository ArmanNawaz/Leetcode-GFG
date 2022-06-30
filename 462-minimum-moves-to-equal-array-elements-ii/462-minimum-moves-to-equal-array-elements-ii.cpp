class Solution {
public:
    int minMoves2(vector<int>& nums) {
        return daily(nums);
    }
private:
    int daily(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int req = 0;
        if(n % 2 == 0)
            req = (nums[n / 2 - 1] + nums[n / 2]) / 2;
        else
            req = nums[n / 2]; 
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            ans += abs(nums[i] - req);
        }
        return ans;
    }
};