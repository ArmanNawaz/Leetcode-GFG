class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int limit = nums[0];
        int count = 0;
        for (int i=1;i<nums.size();i++){
            if (nums[i]<limit){
                if (i<2 || nums[i-2]<=nums[i]){
                    limit = nums[i];
                }
                if (++count==2) return false;
            }else
                limit = nums[i];
        }
        return true;
    }
};