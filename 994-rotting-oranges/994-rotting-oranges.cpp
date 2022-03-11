class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return channaSir(grid);
    }
private:
    
    int channaSir(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    ++fresh;
            }
        }
        if(q.empty()){
            if(fresh == 0) return 0;
            return -1;
        }
        
        
        int level = 0;
        while(!q.empty()){
            int levelLen = q.size();
            while(levelLen--){
                auto [i, j] = q.front();
                
                q.pop();
                
                if(i-1 >= 0 && grid[i-1][j] == 1){
                    --fresh;
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                }
                if(j-1 >= 0 && grid[i][j-1] == 1){
                    --fresh;
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                }
                if(i+1 <= m-1 && grid[i+1][j] == 1){
                    --fresh;
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                }
                if(j+1 <= n-1 && grid[i][j+1] == 1){
                    --fresh;
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                }
            }
            ++level;
        }
        if(fresh > 0) return -1;
        return level-1;
    }
};