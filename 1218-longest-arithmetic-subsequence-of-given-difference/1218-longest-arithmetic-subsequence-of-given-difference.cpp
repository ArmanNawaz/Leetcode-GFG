class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        return solve(arr, difference);
    }
private:
    int solve(vector<int>& arr, int diff) {
        unordered_map<int, int> hashMap;
        int ans = 1;
        
        for(int i = 0; i < arr.size(); ++i) {
            hashMap[arr[i]] = hashMap[arr[i] - diff] + 1;
            ans = max(ans, hashMap[arr[i]]);
        }
        return ans;
    }
};