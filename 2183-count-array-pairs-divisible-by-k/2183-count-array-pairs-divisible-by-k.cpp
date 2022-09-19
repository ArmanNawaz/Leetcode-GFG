class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        long ans = 0;
        unordered_map<int, int> hashMap;
        
        for(int i = 0; i < n; ++i) {
            int gcd1 = __gcd(nums[i], k);
            
            for(auto entry: hashMap) {
                int gcd2 = entry.first;
                
                if(((long long)gcd1 * (long long)gcd2) % k == 0)
                    ans += entry.second;
            }
            hashMap[gcd1]++;
        }
        return ans;
        
    }
};