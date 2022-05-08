class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        return solve(arr);
    }
private:
    int solve(vector<int>& arr) {
        int ans = 0;
        int maxValue = 0;
        for(int i = 0; i < arr.size(); ++i) {
            maxValue = max(maxValue, arr[i]);
            if(maxValue == i)
                ++ans;
        }
        return ans;
    }
};