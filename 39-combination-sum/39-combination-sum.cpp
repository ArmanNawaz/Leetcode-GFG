class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> partialAns;
        int idx = candidates.size()-1;
        // solve(candidates, target, idx, partialAns, ans);
        solve1(candidates, target, 0, partialAns, ans);
        
        return ans;
    }
private:
    void solve1(vector<int>& candidates, int target,
                              int idx, vector<int>& partialAns, vector<vector<int>>& ans) {
        if(target == 0){
            ans.push_back(partialAns);
            return;
        }
        if(idx == candidates.size()) return;
        
        solve1(candidates, target, idx+1, partialAns, ans);
        
        if(target >= candidates[idx]){
            partialAns.push_back(candidates[idx]);
            solve1(candidates, target - candidates[idx], idx, partialAns, ans);
            partialAns.pop_back();
        }
    }
     
    
    
    
    void solve(vector<int>& candidates, int& target,
                              int idx, vector<int>& partialAns, vector<vector<int>>& ans) {
        if(target == 0){
            ans.push_back(partialAns);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = idx; i >= 0; --i){
            int x = candidates[i];
            partialAns.push_back(x);
            target -= x;
            
            solve(candidates, target, i, partialAns, ans);
            
            partialAns.pop_back();
            target += x;
        }        
        
    }
};