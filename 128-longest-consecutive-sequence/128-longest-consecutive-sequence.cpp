class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        return daily(nums);
    }
private:
    int daily(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxLen = 0;
        
        for(int n: seen) {
            if(seen.count(n - 1)) continue;
            
            int count = 1;
            while(seen.count(n + count)) ++count;
            maxLen = max(maxLen, count);
        }
        
        return maxLen;
    }
};