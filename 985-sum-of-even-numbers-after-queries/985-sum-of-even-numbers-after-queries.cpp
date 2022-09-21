class Solution {
    bool isEven(int& x) {
        return (x & 1) == 0;
    }
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        
        int evenSum = 0;
        for(int& x: nums) {
            if(isEven(x))
                evenSum += x;
        }
        
        for(vector<int>& query: queries) {
            int& val = query[0];
            int& index = query[1];
            
            int initialValue = nums[index];
            nums[index] = initialValue + val;
            int updatedValue = nums[index];
            
            if(isEven(initialValue)) {
                evenSum -= initialValue;
            }
            if(isEven(updatedValue)) {
                evenSum += updatedValue;
            }
            
            
            ans.push_back(evenSum);
        }
        return ans;
   }
};