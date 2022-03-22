class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        
        return m + n - 2 * findLCS(word1, word2, m, n);
    }
private:
    int findLCS(string word1, string word2, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};