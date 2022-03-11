class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        return bruteforce(nums);
    }
private:
    vector<int> bruteforce(vector<int>& nums) {
        vector<int> odds;
        vector<int> evens;
        
        for(int n: nums) {
            if(n % 2 == 0) evens.push_back(n);
            else odds.push_back(n);
        }
        int i = 0;
        for(int n: evens)
            nums[i++] = n;
        
        for(int n: odds)
            nums[i++] = n;
        return nums;
    }
};