class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        return daily(nums, x);
    }
private:
    int daily(vector<int>& nums, int x) {
        int sum = 0, i = 0, j = 0;
        int n = nums.size();
        int ans = INT_MAX;
        
        sum = accumulate(nums.begin(), nums.end(), 0);
        while(i <= j) {
            if(sum >= x) {
                if(sum == x)
                    ans = min(ans, n + i - j);
                
                if(j < n)
                    sum -= nums[j++];
                else
                    break;
            }
            else
                sum += nums[i++];
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
           
    }
};