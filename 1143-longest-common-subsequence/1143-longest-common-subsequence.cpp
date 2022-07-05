class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return recurseDp(text1, text2, 0, 0, dp);
        // return bruteForce(text1, text2, 0, 0);
    }
private:
    int bruteForce(string text1, string text2, int i, int j) {
        if(i >= text1.size() || j >= text2.size())
            return 0;
        
        if(text1[i] == text2[j])
            return bruteForce(text1, text2, i + 1, j + 1) + 1;
        
        int take = bruteForce(text1, text2, i + 1, j);
        int notTake = bruteForce(text1, text2, i, j + 1);
        
        return max(take, notTake);
    }
    
    int recurseDp(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        if(i >= text1.size() || j >= text2.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(text1[i] == text2[j])
            return dp[i][j] = recurseDp(text1, text2, i + 1, j + 1, dp) + 1;
        
        int take = recurseDp(text1, text2, i + 1, j, dp);
        int notTake = recurseDp(text1, text2, i, j + 1, dp);

        return dp[i][j] = max(take, notTake);        
        
    }
};