class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        return rahulSir(nums);
        // return solve(nums);        
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
    
    vector<int> rahulSir(vector<int>& nums) {
        int bitmask = 0;
        
        for(int n: nums)
            bitmask ^= n;
        
        int diff = bitmask & (-1 * (unsigned int)bitmask);
        int y = 0;
        
        for(int n: nums) {
            if((n & diff) != 0)
                y ^= n;
        }
        int x = bitmask ^ y;
        
        return {x, y};
    }
};