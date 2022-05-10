class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return solve2(k, n);
        // return solve(k, n);
    }
private:
    // Daily
    void dfs(int k, int target, int start, int end, vector<int>& partialAns, vector<vector<int>>& ans) {
        // Base case
        // If no more elements can be picked
        if(k == 0) {
            // if we reached target
            if(target == 0)
                ans.push_back(partialAns);  // include it in ans
            return;
        }
        
        // check for all other elements
        for(int num = start; num < end; ++num) {
            partialAns.push_back(num);  // include the element
            dfs(k - 1, target - num, num + 1, end, partialAns, ans); // move for next elements
            partialAns.pop_back();  // remove the element - Backtracking step
        }
    }
    
    vector<vector<int>> solve(int k, int n) {
        vector<vector<int>> ans;
        vector<int> partialAns;
        
        int start = 1, end = 10;
        
        dfs(k, n, start, end, partialAns, ans);
        
        return ans;
    }
    
    
    
    // Asim's idea
    void dfs2(int k, int target, int num, vector<int>& partialAns, vector<vector<int>>& ans) {
        if(k == 0){
            if(target == 0) {
                ans.push_back(partialAns);
            }
            return;
        }
        if(num > 9)
            return;
        
        dfs2(k, target, num + 1, partialAns, ans);
        partialAns.push_back(num);
        dfs2(k - 1, target - num, num + 1, partialAns, ans);
        partialAns.pop_back();
        
        return;
    }
    vector<vector<int>> solve2(int k, int n) {
        vector<vector<int>> ans;
        vector<int> partialAns;
        
        dfs2(k, n, 1, partialAns, ans);
        
        return ans;
    }
    
    
    
    
    
    
    
    
    
    
};