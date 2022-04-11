class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        return solve(image, sr, sc, newColor);
    }
private:
    void dfs(vector<vector<int>>& image, int x, int y, int newColor, vector<vector<bool>>& visited) {
        
        int oldColor = image[x][y];
        image[x][y] = newColor;
        
        visited[x][y] = true;
        
        if((x >= 1) && (image[x - 1][y] == oldColor) && (!visited[x - 1][y]))
            dfs(image, x - 1, y, newColor, visited);
            
        if (x < (image.size() - 1) && (image[x + 1][y] == oldColor) && (!visited[x + 1][y]))
            dfs(image, x + 1, y, newColor, visited);
        
        if ((y >= 1) && (image[x][y - 1] == oldColor) && (!visited[x][y - 1]))
            dfs(image, x, y - 1, newColor, visited);
        
        if (y < (image[0].size() - 1) && (image[x][y + 1] == oldColor) && (!visited[x][y + 1]))
            dfs(image, x, y + 1, newColor, visited);
            
    }
    vector<vector<int>> solve(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        dfs(image, sr, sc, newColor, visited);
        return image;
    }
};