class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int evenCount = 0, oddCount = 0;
        int ans = 0;
        int mod = 1e9 + 7;
        
        if((arr[0] & 1) == 0)
            evenCount = 1;
        else {
            oddCount = 1;
            ++ans;
        }
        
        for(int i = 1; i < n; ++i) {
            if((arr[i] & 1) == 0) {
                evenCount += 1;
            } else {
                int tmp = oddCount;
                oddCount = evenCount + 1;
                evenCount = tmp;
            }
            ans = (ans + oddCount) % mod;
        }
        return ans;
    }
};