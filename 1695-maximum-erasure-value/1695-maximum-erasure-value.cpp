class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        return daily(nums);
    }
private:
    int daily(vector<int>& nums) {
        set<int> seen;
        int wStart = 0;
        int maxSum = INT_MIN, winSum = 0;
        
        for(int wEnd = 0; wEnd < nums.size(); ++wEnd) {
            while(seen.find(nums[wEnd]) != seen.end()) {
                seen.erase(nums[wStart]);
                winSum -= nums[wStart++];
            }
            winSum += nums[wEnd];
            maxSum = max(maxSum, winSum);
            seen.insert(nums[wEnd]);
        }
        return maxSum;
    }
};