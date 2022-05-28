class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int numsSum = 0;
        
        for(int num: nums) {
            numsSum += num;
        }
        
        int nSum = n * (n + 1) / 2;
        
        return nSum - numsSum;
    }
};