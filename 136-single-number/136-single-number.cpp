class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return channaSir(nums);
    }
private:
    int channaSir(vector<int>& nums) {
        int req = 0;
        
        for(int n: nums)
            req ^= n;
        return req;
    }
};