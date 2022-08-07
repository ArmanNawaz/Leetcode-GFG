// a = 1, e = 2, i = 3, o = 4, u = 5
class Solution {
public:
    int countVowelPermutation(int n) {
        return daily(n);
    }
private:
    int recurse(int ch, int count, vector<vector<int>>& dp) {
        int mod = 1e9 + 7;
        
        if(count == 0) return 1;
        
        if(dp[ch][count] != -1)
            return dp[ch][count];
        
        int ans = 0;
        
        if(ch == 1) {
            ans += recurse(2, count - 1, dp);
            ans = ans % mod;
        }
        
        else if(ch == 2) {
            for(int x: {1, 3}) {
                ans += recurse(x, count - 1, dp);
                ans = ans % mod;
            }
        }
        
        else if(ch == 3) {
            for(int x: {1, 2, 4, 5}) {
                ans += recurse(x, count - 1, dp);
                ans = ans % mod;
            }
            
        }
        
        else if(ch == 4) {
            for(int x: {3, 5}) {
                ans += recurse(x, count - 1, dp);
                ans = ans % mod;
            }
        }
        
        else if(ch == 5) {
            ans += recurse(1, count - 1, dp);
            ans = ans % mod;
        }
        
        return dp[ch][count] = ans;
    }
    
    int daily(int n) {
        int ans = 0;
        int mod = 1e9 + 7;
        vector<vector<int>> dp(6, vector<int>(n, -1));
        
        for(int i = 1; i < 6; ++i) {
            ans += recurse(i, n - 1, dp);
            ans = ans % mod;
        }
        
        return ans;
    }
};