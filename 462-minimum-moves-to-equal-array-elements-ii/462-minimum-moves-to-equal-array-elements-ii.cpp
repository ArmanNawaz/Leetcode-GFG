class Solution {
public:
    int minMoves2(vector<int>& nums) {
        return daily(nums);
    }
private:
    // O(n logn) Time and O(1) extra space
    int daily(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int req = nums[n / 2]; 
        
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            ans += abs(nums[i] - req);
        }
        
        return ans;
    }
};