class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        return solve(nums);
    }
    
private:
    // Daily
    int solve(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        
        stack<int> stack;
        
        int start = 1e6, end = -1;
        
        for(int i = 0; i < nums.size(); ++i) {
            while(!stack.empty() && nums[stack.top()] > nums[i]) {
                int idx = stack.top();
                stack.pop();
                start = min(start, idx);
            }
            stack.push(i);
        }
        
        while(!stack.empty())
            stack.pop();
        
        for(int i = nums.size() - 1; i >= 0; --i) {
            while(!stack.empty() && nums[stack.top()] < nums[i]) {
                int idx = stack.top();
                stack.pop();
                end = max(end, idx);
            }
            stack.push(i);
        }
        
        int ans = end - start + 1;
        if(ans < 0)
            return 0;
        return ans;
    }
};