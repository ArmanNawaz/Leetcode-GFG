class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        return solve(nums);        
    }
private:
    vector<int> solve(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for(int x: nums)
            freq[x]++;
        
        vector<int> ans;
        
        for(auto entry: freq)
            if(entry.second == 1)
                ans.push_back(entry.first);
        return ans;
    }
};