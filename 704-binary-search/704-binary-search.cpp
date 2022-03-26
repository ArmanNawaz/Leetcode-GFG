class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target);
    }
private:
    int binarySearch(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};