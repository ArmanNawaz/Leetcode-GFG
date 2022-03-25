class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        return twoPointer(nums);
        return bruteforce(nums);
    }
private:
    // O(n) Time and O(n) extra space
    vector<int> twoPointer(vector<int>& nums){
        int i = 0, j = nums.size() - 1;
        vector<int> res;
        
        while(i <= j){
            if(abs(nums[i]) < abs(nums[j])){
                res.push_back(nums[j] * nums[j]);
                j--;
            }
            else{
                res.push_back(nums[i] * nums[i]);
                i++;
            }
            
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
    
    // O(nlogn) Time and O(1) extra space
    vector<int> bruteforce(vector<int>& nums){
        for(int i = 0; i < nums.size(); i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};