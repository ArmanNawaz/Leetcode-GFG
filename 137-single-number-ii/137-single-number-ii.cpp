class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return rahulSir(nums);
    }
private:
    int rahulSir(vector<int>& nums) {
        int b1 = 0, b2 = 0;
        
        for(int n: nums) {
            b1 = (~b2) & (b1 ^ n);
            b2 = (~b1) & (b2 ^ n);
        }
        return b1;
    }
};