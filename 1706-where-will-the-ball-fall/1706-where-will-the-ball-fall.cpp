class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> paths(m + 1, vector<int>(n, -1));
        
        for(int i = 0; i < n; ++i)
            paths[0][i] = i;
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i - 1][j] == 1) {
                    if(j < n - 1 && grid[i - 1][j + 1] == 1) {
                        paths[i][j + 1] = paths[i - 1][j];
                    }
                }
                else {
                    if(j > 0 && grid[i - 1][j - 1] == -1) {
                        paths[i][j - 1] = paths[i - 1][j];
                    }
                }
            }
        }
        
        vector<int> ans(n, -1);
        
        for(int i = 0; i < n; ++i) {
            if(paths[m][i] >= 0)
                ans[paths[m][i]] = i;
        }
        return ans;
    }
};