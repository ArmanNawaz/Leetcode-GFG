class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        return solve(grid, k);
    }
private:
    vector<vector<int>> solve(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int x = (i + (j + k) / m) % n;
                int y = (j + k) % m;
                
                ans[x][y] = grid[i][j];
            }
        }        
        return ans;
    }
};