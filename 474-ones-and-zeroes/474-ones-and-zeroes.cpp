class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return memoize(strs, m, n, strs.size(), dp);
        // return solve(strs, m, n);
    }
private:
    bool isValid(string s, int m, int n) {
        for(char c: s) {
            if(c == '0') --m;
            else --n;
            
            if(m < 0 || n < 0) return false;
        }
        return true;
    }
    
    int solve(vector<string>& strs, int m, int n) {
        int ans = 0;
        for(auto s: strs) {
            if(isValid(s, m, n))
                ++ans;
        }
        return ans;
    }
    
    int memoize(vector<string>& strs, int z, int o, int idx, vector<vector<vector<int>>>& dp){
        
        if(idx == 0 || (z <= 0 && o <= 0)){
            return 0;
        }
        
        if(dp[idx][z][o] != -1) return dp[idx][z][o];
        
        int zeros = 0, ones = 0, pick = 0, nonPick = 0;
        for(auto c: strs[idx-1]){
            if(c=='1') ones++;
            else zeros++;
        }
        
        if(zeros <= z && ones <= o){
            pick = 1 + memoize(strs, z-zeros, o-ones, idx-1, dp);
        }
        else 
        nonPick = memoize(strs, z, o, idx-1, dp);
        
        nonPick = memoize(strs, z, o, idx-1, dp);
        
        return dp[idx][z][o] = max(pick, nonPick);
        
    }
};