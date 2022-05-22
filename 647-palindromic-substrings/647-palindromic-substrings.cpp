class Solution {
public:
    int countSubstrings(string s) {
        return daily(s);
    }
private:
    int daily(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        
        for(int gap = 0; gap < n; ++gap) {
            int i = 0;
            for(int j = gap; j < n; ++j, ++i) {
                if(gap == 0) {
                    dp[i][j] = true;
                    ++count;
                }
                else if(gap == 1 && s[i] == s[j]) {
                    dp[i][j] = true;
                    ++count;
                }
                else if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ++count;
                }
            }
        }
        return count;
    }
};