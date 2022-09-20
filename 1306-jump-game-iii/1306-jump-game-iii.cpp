class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        return recurse(arr, start);
    }
private:
    bool recurse(vector<int>& arr, int idx) {
        if(idx < 0 || idx >= arr.size()) return false;
        
        if(arr[idx] == 0) return true;
        if(arr[idx] < 0) return false;
        arr[idx] = -1 * arr[idx];
        
        return recurse(arr, idx - arr[idx]) || recurse(arr, arr[idx] + idx);
    }
};