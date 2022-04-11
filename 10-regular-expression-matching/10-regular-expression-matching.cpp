class Solution {
public:
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
private:
    // Rahul Sir
    bool solve(string s, string p) {
        if(p == ".*")
            return true;
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        for(int i = 1; i <= m; ++i) {
            if(p[i - 1] == '*')
                dp[i][0] = dp[i - 2][0];
        }
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                
                if((p[i - 1] == '.') || (p[i - 1] == s[j - 1]))
                    dp[i][j] = dp[i - 1][j - 1];
                
                else if(p[i - 1] == '*') {
                    dp[i][j] = dp[i - 2][j];
                    
                    if((p[i - 2] == s[j - 1]) || (p[i - 2] == '.'))
                        dp[i][j] = dp[i - 2][j] || dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
}; 