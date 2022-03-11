class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        return solve(nums);
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
    
    vector<int> solve(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        
        while(i < j) {
            while(i < nums.size() && nums[i] % 2 == 0) ++i;
            while(j > 0 && nums[j] % 2 != 0) --j;
            
            if(i < j) swap(nums[i], nums[j]);
        }
        return nums;
    }
};