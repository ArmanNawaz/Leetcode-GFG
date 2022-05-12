class Solution {
public:
    int countVowelStrings(int n) {
        return recurse(n, 0);
    }
private:
    // Daily
    int recurse(int n, int idx) {
        
        // if n size string is formed or no more vowel left to include
        if(idx >= 5 || n == 0) {
            if(n == 0)
                return 1;
            return 0;
        }
        
        
        // include current character and move for next set of vowels i.e, "aeiou"
        int inc = recurse(n - 1, idx);
        
        // exclude current character and recurse for next character
        int exc = recurse(n, idx + 1);
        
        return inc + exc;
    }
};