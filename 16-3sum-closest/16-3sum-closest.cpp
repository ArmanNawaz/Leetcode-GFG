class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        return twoptr(nums, target);
        return bruteforce(nums, target);
    }
private:
    // O(n^3) Time and O(1) extra space
    int bruteforce(vector<int>& nums, int target){
        int n = nums.size();
        int minDiff = INT_MAX;
        int closestSum = 0;
        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                for(int k = j+1; k < n; k++){
                    // O(i, j , k) is a triplet
                    int diff = abs(nums[i] + nums[j] + nums[k] - target);
                    if(diff < minDiff){
                        minDiff = diff;
                        closestSum = nums[i] + nums[j] + nums[k];
                    }
                }
            } 
        }
        return closestSum;
    }
    
    int twoptr(vector<int>& nums, int target){
        int closestSum = 0;
        int minDiff = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int t = target - nums[i];
            int j = i+1;
            int k = n - 1;
            while(j < k){
                int sum = nums[j] + nums[k];
                int diff = abs(sum - t);
                if(diff < minDiff){
                    minDiff = diff;
                    closestSum = sum + nums[i];
                }
                if(sum < t) j++;
                else k--;
            }
        }
        return closestSum;
    }
};