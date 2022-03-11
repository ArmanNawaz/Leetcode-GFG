class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        return slidingWindow(target, nums);
    }
private:
    // O(n) time and O(1) extra space
    int slidingWindow(int target, vector<int>& nums) {
        int wStart = 0, minSize = INT_MAX, wSum = 0;
        
        for(int wEnd = 0; wEnd < nums.size(); ++wEnd) {
            wSum += nums[wEnd];
            
            while(wSum >= target) {
                wSum -= nums[wStart];
                minSize = min(minSize, wEnd - wStart + 1);
                ++wStart;
            }
        }
        if(minSize >= nums.size()+1)
            return 0;
        return minSize;
    }
};