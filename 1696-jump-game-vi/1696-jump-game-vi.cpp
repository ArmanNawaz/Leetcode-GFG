class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> maxHeap;
        vector<int> dp(n, 0);
        
        maxHeap.push({nums[0], 0});
        dp[0] = nums[0];
        
        for(int i = 1; i < n; ++i) {
            while(maxHeap.top().second < i - k)
                maxHeap.pop();
            
            dp[i] = nums[i] + dp[maxHeap.top().second];
            
            maxHeap.push({dp[i], i});            
        }
        return dp[n - 1];
    }
};