class Solution {
    int m;
    int n;
public:
    // O(mn+e) = O(mn + 4mn) = O(mn) Time, *[O(mn) extra space] and O(mn) stack space
    int numIslands (vector<vector<char>>& grid) {
        m = grid.size(); 
        n = grid[0].size(); 
        // vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        int countIslands = 0; 
        for(int i = 0; i < m; ++i) {
            // [0, m-1] 
            for(int j = 0; j < n; ++j) {
                // [e, n-1] 
                // if(grid[i][j] == '1' && visited[i][j] == false) {
                if(grid[i][j] == '1'){
                    ++countIslands;
                    dfs(grid, i, j);
                }
            }
        }
        return countIslands;
    }
                    
private: 
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        // for each neighbor of vertex (i, j), 
        if(i-1 >= 0 && grid[i-1][j] == '1') {
            dfs(grid, i-1, j); // up cell
        }
        if(j-1 >= 0 && grid[i][j-1] == '1') {
            dfs(grid, i, j-1); // left cell
        }

        if(i+1 < m && grid[i+1][j] == '1') {
            dfs(grid, i+1, j); // down cell
        }
        if(j+1 < n && grid[i][j+1] == '1') {
            dfs (grid, i, j+1); // right cell
        }
        return;
    }
};