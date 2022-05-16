class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return solve(arr, k);
    }
private:
    // Rahul sir
    // 16 May 2022
    int solve(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = arr[0];
        
        for(int i = 1; i < n; ++i) {
            int maxEle = arr[i];
            for(int j = i; j >= max(0, i - k + 1); --j) {
                maxEle = max(maxEle, arr[j]);
                int winSize = i - j + 1;
                if(j > 0)
                    dp[i] = max(dp[i], maxEle * winSize + dp[j - 1]);
                else 
                    dp[i] = max(dp[i], maxEle * winSize);
            }
        } 
        return dp[n- 1];
    }
};