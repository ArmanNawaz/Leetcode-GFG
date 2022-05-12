class Solution {
public:
    int countVowelStrings(int n) {
        return solve(n);
        // return recurse(n, 0);
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
    
    int recurse2(int n, int idx, vector<vector<int>>& dp) {
        
        if(dp[n][idx] != INT_MIN) {
            return dp[n][idx];
        }
        
        // if n size string is formed or no more vowel left to include
        if(idx >= 5 || n == 0) {
            if(n == 0)
                return 1;
            return 0;
        }
        
        
        // include current character and move for next set of vowels i.e, "aeiou"
        int inc = recurse2(n - 1, idx, dp);
        
        // exclude current character and recurse for next character
        int exc = recurse2(n, idx + 1, dp);
        
        return dp[n][idx] = inc + exc;
    }
    int solve(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6, INT_MIN));
        
        return recurse2(n, 0, dp);
    }
};