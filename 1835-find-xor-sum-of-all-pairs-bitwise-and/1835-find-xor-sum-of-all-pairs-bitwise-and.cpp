class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        return solve(arr1, arr2);
    }
private:
    // Aakash Sir
    int solve(vector<int>& arr1, vector<int>& arr2) {
        int a = 0, b = 0;
        
        for(int n: arr1)
            a ^= n;
        for(int n: arr2)
            b ^= n;
        
        return a & b;
    }
};