class Solution {
public:
    string longestPalindrome(string s) {
        return daily(s);
    }
private:
    string daily(string& s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; ++i) {
            dp[i][0] = true;
            dp[0][i] = true;
        }
        int start = 0, end = 0;
        for(int gap = 0; gap < n; ++gap) {
            for(int i = 0, j = gap; j < n; ++i, ++j) {
                if(gap == 0) {
                    dp[i][j] = true;
                    start = i;
                    end = j;
                }
                
                else if(gap == 1 && s[i] == s[j]) {
                    dp[i][j] = true;
                    start = i;
                    end = j;
                }
                
                else if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    end = j;
                }
            }
        }
        string ans = "";
        for(int i = start; i <= end; ++i)
            ans += s[i];
        return ans;
    }
};