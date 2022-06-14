class Solution {
public:
    int minDistance(string word1, string word2) {
        return daily(word1, word2);
    }
private:
    int lcs(string& word1, string& word2) {
        int m = word1.length();
        int n = word2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[m][n];
    }
    
    
    int daily(string& word1, string& word2) {
        int m = word1.length();
        int n = word2.length();
        
        return m + n - 2 * lcs(word1, word2);
    }
};