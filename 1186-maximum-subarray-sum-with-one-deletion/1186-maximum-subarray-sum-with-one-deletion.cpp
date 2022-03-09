class Solution {
public:
    int maximumSum(vector<int>& arr) {
        return solve(arr);
    }
private:
    int solve(vector<int>& arr) {
        int n = arr.size();
        vector<int> f(n, 0);
        vector<int> b(n, 0);
        
        f[0] = arr[0];
        b[n-1] = arr[n-1];
        
        int maxSoFar = f[0];
        
        
        // Kadane forward
        for(int i = 1; i < n; ++i) {
            if(f[i-1] < 0) f[i] = arr[i];
            else f[i] = f[i-1] + arr[i];
            maxSoFar = max(maxSoFar, f[i]);
        }
        // Kadane Backward
        for(int i = n-2; i > 0; --i) {
            if(b[i+1] < 0) b[i] = arr[i];
            else b[i] = b[i+1] + arr[i];
            maxSoFar = max(maxSoFar, b[i]);
        }
        
        int res = maxSoFar;
        for(int i = 1; i < n - 1; ++i) {
            res = max(res, f[i-1] + b[i+1]);
        }
        return res;        
    }
};