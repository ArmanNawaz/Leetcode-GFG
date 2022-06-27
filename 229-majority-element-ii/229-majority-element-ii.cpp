class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // return bruteforce(nums);
        return hashMap(nums);
    }
private: 
    // (n ^ 2) Time and O(n) extra space - TLE
    vector<int> bruteforce(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_set<int> seen;
        
        for(int i = 0; i < n; ++i) {
            int freq = 1;
            for(int j = i + 1; j < n; ++j) {
                if(nums[i] == nums[j])
                    ++freq;
            }
            if((freq > n / 3) && (seen.find(nums[i]) == seen.end())) { 
                ans.push_back(nums[i]);
                seen.insert(nums[i]);
            }
        }
        return ans;
    }
    
    
    // O(n) Time and O(n) extra space
    vector<int> hashMap(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> hashMap;
        
        for(int x: nums) 
            hashMap[x]++;
        vector<int> ans;
        
        for(auto entry: hashMap) {
            if(entry.second > n / 3)
                ans.push_back(entry.first);
        }
        return ans;
    }
};