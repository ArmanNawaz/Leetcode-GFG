class Solution {
public:
    int maxArea(vector<int>& height) {
        return solve(height);
    }
private:
    int solve(vector<int>& height) {
        int ans = INT_MIN;
        int i = 0, j = height.size() - 1;
        
        while(i < j) {
            ans = max(ans, (j - i) * min(height[i], height[j]));
            height[i] < height[j] ? ++i: --j;
        }
        return ans;
    }
};