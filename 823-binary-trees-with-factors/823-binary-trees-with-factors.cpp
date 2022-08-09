class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        return daily(arr);
    }
private:
    int daily(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mod = 1e9 + 7;
        unordered_map<int, long> dp;
        
        for(int i = 0; i < arr.size(); ++i) 
            dp[arr[i]] = 1;
        
        for(int i = 1; i < arr.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                int q = arr[i] / arr[j];
                
                if(q < 2) break;
                
                if(arr[i] % arr[j] == 0 and dp.find(q) != dp.end()) {
                    dp[arr[i]] += dp[arr[j]] * dp[q];
                    dp[arr[i]] %= mod;
                }
            }
        }
        
        int ans = 0;
        for(auto entry: dp) {
            ans += entry.second;
            ans %= mod;
        }
        return ans;
    }
};