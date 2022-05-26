class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bit_manipulation(n);
    }
private:
    int bit_manipulation(uint32_t n){
        int ans = 0;
        while(n){
            n = n & (n-1);
            ++ans;
        }
        return ans;
    }
};