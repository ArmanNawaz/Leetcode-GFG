class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arrSum = 0;
        int n = nums.size();
        
        for(auto i: nums)
            arrSum += i;
        
        int nSum = n * (n + 1) / 2;
        
        return nSum - arrSum;            
    }
};