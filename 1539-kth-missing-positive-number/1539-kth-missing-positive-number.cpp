class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {        
        int low = 0, high = arr.size() - 1;
        int mid = 0;
        
        while(low <= high) {            
            mid = low + (high - low) / 2;
            
            int numberOfMissing = arr[mid] - (mid + 1);
            
            if(numberOfMissing < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
            
        }
        int lastMissing = arr[mid] - (mid + 1);
        
        if(k > lastMissing)
            return arr[mid] + k - lastMissing;
        
        if(mid == 0) return k;
        
        lastMissing = arr[mid - 1] - mid;
        return arr[mid - 1] + k - lastMissing;
    }
};