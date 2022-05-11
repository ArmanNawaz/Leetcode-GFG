class Solution {
public:
    int countVowelStrings(int n) {
        return solve(n);
    }
private:
    // Daily
    void recurse(int n, int idx, int& count) {
        
        // if n size string is formed or no more vowel left to include
        if(idx >= 5 || n == 0) {
            if(n == 0)
                ++count;
            return;
        }
        
        // include current character and move for next set of vowels i.e, "aeiou"
        recurse(n - 1, idx, count);
        
        // exclude current character and recurse for next character
        recurse(n, idx + 1, count);
    }
    
    int solve(int n) {
        
        int count = 0;
        
        recurse(n, 0, count);
        return count;
    }
};