class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        return solve(n, k);
    }
private:
    void recurse(int n, int idx, int k, vector<vector<int>>& ans, vector<int>& partialAns) {
        
        if(partialAns.size() == k) {
            ans.push_back(partialAns);
            return;
        }
        
       
        for(int i = idx; i <= n; ++i) {
            partialAns.push_back(i);
            recurse(n, i + 1, k, ans, partialAns);
            partialAns.pop_back();
        }
    }
    
    vector<vector<int>> solve(int n, int k) {
        vector<vector<int>> ans;
        
        vector<int> partialAns;
        // for(int i = 1; i <= n; ++i)
            recurse(n, 1, k, ans, partialAns);
        
        return ans;
        
    }
};