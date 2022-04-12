class Solution {
public:
    bool isPowerOfTwo(int n) {
        return solve(n);    
    }
private:
    bool solve(int n) {
        if(n == 0 || n == -2147483648)
            return false;
        
        n = n & (n - 1);
        
        if(n == 0)
            return true;
        return false;
    }
};