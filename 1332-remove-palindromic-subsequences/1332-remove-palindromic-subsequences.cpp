class Solution {
public:
    int removePalindromeSub(string s) {
        return solve(s);
    }
private:
    int solve(string& s) {
        string x = s;
        reverse(x.begin(), x.end());
        
        if(s == x)
            return 1;
        return 2;
            
    }
};