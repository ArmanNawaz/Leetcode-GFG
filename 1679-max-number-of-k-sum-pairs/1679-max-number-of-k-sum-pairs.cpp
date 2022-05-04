class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        return solve(nums, k);
    }
private:
    int solve(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0;
        
        for(auto cur: nums){
            if(freq[k - cur] > 0) {
                ans++; 
                freq[k - cur]--;
            }
            else 
                freq[cur]++;
        }
        return ans;
    }
};