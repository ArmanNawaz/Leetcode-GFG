class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        return optimised(nums);
        // return solve1(nums);
        // return bruteForce(nums);
    }
private:
    // Daily
    
    // O(n) Time and O(1) space 
    bool optimised(vector<int>& nums) {
        int n = nums.size();
        int top = n, thirdElement = INT_MIN;
        
        for(int i = n - 1; i >= 0; --i) {
            if(thirdElement > nums[i]) return true;
            
            while(top < n && nums[i] > nums[top]) 
                thirdElement = nums[top++];
            nums[--top] = nums[i];
        }
        return false;
    }
    
    
    // O(n^2) Time and O(1) space - TLE
    bool solve1(vector<int>& nums) {
        int n = nums.size();
        int minValue = INT_MAX;
        
        for(int j = 0; j < n; ++j) {
            minValue = min(minValue, nums[j]);
            
            if(minValue == nums[j])
                continue;
            
            for(int k = n - 1; k > j; --k) {
                if(minValue < nums[k] && nums[k] < nums[j])
                        return true;
            }
        }
        return false;
    }    
    
    
    // O(n^3) Time and O(1) space - TLE
    bool bruteForce(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 2; ++i) {
            for(int j = i + 1; j < n - 1; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    if(nums[i] < nums[k] && nums[k] < nums[j])
                        return true;
                }
            }
        }
        return false;
    }
};