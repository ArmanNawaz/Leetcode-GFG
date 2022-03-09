class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp;
        for(int i = 0; i < values.size(); ++i){
            vector<int> temp;
            for(int j = 0; j < values.size(); ++j){
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }
        return dp_mem(values, 1, values.size()-1, dp);
        // return recursive(values, 1, values.size()-1);
    }
private:
    int dp_mem(vector<int>& values, int i, int j, vector<vector<int>>& dp){
        if(i == j){
            dp[i][j] = 0;
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int minValue = INT_MAX;
        
        for(int k = i; k < j; ++k){
            int temp = dp_mem(values, i, k, dp) + dp_mem(values, k+1, j, dp) + values[i-1]*values[k]*values[j];
            minValue = min(minValue, temp);
        }
        dp[i][j] = minValue;
        return dp[i][j];
    }
    
    
    // mcm function- recursive- TLE
    int recursive(vector<int>& values, int i, int j){
        if(i == j) return 0;
        int minValue = INT_MAX;
        
        for(int k = i; k < j; ++k){
            int temp = recursive(values, i, k) + recursive(values, k+1, j) + values[i-1]*values[k]*values[j];
            minValue = min(minValue, temp);
        }
        return minValue;
    }
};