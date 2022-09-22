class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        vector<bool> dp(n, false);
        dp[0] = true;
        int count = 0;
        
        for(int i = 1; i < n; ++i) {
            if(i > maxJump)
                count -= dp[i - maxJump - 1];
            
            if(i >= minJump)
                count += dp[i - minJump];
            
            if(count > 0 && s[i] == '0')
                dp[i] = true;
        }
        return dp[n - 1];
    }
};