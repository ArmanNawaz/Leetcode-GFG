class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        return solve(word1, word2, m, n, dp);
    }
private:
    int solve(string& s1, string& s2, int m, int n, vector<vector<int>>& dp) {
        if(s1.length() == 0)
            return dp[m][n] = n;
        if(s2.length() == 0)
            return dp[m][n] = m;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(m == 0)
            return dp[m][n] = n;
        if(n == 0)
            return dp[m][n] = m;
        
        if(s1[m - 1] == s2[n - 1])
            return dp[m][n] = solve(s1, s2, m - 1, n - 1, dp);
        else {
            int a = solve(s1, s2, m - 1, n, dp);
            int b = solve(s1, s2, m, n - 1, dp);
            int c = solve(s1, s2, m - 1, n - 1, dp);
            
            return dp[m][n] = min(a, min(b, c)) + 1;
        }
    }
};