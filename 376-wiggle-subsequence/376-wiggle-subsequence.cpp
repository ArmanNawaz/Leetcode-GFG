class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        return daily(nums);
    }
private:
    int daily(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return 1;
        
        stack<int> modified;
        int i = 0;
        while(i < n - 1 && nums[i] == nums[i + 1]) ++i;
        
        if(i == n - 1) return 1;
        
        bool flag = nums[i] > nums[i + 1]; // true means nums[i] > nums[j]
        
        
        modified.push(nums[i]);
        
        for(; i < n - 1; ++i) {
            if(nums[i] > nums[i + 1]) {
                if(flag == false) 
                    modified.pop();
                
                else flag = false;
                
                modified.push(nums[i + 1]);
            } 
            else if(nums[i] < nums[i + 1]) {
                if(flag == true)
                    modified.pop();
                else flag = true;
                
                modified.push(nums[i + 1]);
            }
        }
        return modified.size();
    }
};