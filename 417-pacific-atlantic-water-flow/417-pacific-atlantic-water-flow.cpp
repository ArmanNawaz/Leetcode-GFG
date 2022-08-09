class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        return rahulSir(heights);
    }
private:
    void dfs(int row, int col, int prev, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        
        if(row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size())
            return;
        
        if(heights[row][col] < prev || ocean[row][col])
            return;
        
        ocean[row][col] = true;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for(auto dir: directions) {
            int x = row + dir[0];
            int y = col + dir[1];
            dfs(x, y, heights[row][col], ocean, heights);
        }
        return;
    }
    
    vector<vector<int>> rahulSir(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        
        for(int col = 0; col < cols; ++col) {
            dfs(0, col, INT_MIN, pacific, heights);
            dfs(rows - 1, col, INT_MIN, atlantic, heights);
        }
        
        for(int row = 0; row < rows; ++row) {
            dfs(row, 0, INT_MIN, pacific, heights);
            dfs(row, cols - 1, INT_MIN, atlantic, heights);
        }
        vector<vector<int>> ans;
        
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};