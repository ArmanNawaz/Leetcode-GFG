class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return solve(grid);
    }
private:
    int solve(vector<vector<int>>& grid){
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n == 1) return 1;
        
        int ans = 1;
        
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        
        while(!q.empty()){
            int adjCell = q.size();
            ++ans;
            
            while(adjCell--) {  
                
                auto cell = q.front();
                q.pop();
                int i = cell.first, j = cell.second;
                
                // up left
                if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 0) {
                    if(i-1 == n-1 && j-1 == n-1) return ans;
                    q.push(make_pair(i-1, j-1));
                    grid[i-1][j-1] = 2;
                }
                // up
                if(i-1 >= 0 && grid[i-1][j] == 0) {
                    if(i-1 == n-1 && j == n-1) return ans;
                    q.push(make_pair(i-1, j));
                    grid[i-1][j] = 2;
                }
                // up right
                if(i-1 >= 0 && j+1 < n && grid[i-1][j+1] == 0) {
                    if(i-1 == n-1 && j+1 == n-1) return ans;
                    q.push(make_pair(i-1, j+1));
                    grid[i-1][j+1] = 2;
                }
                // left
                if(j-1 >= 0 && grid[i][j-1] == 0) {
                    if(i == n-1 && j-1 == n-1) return ans;
                    q.push(make_pair(i, j-1));
                    grid[i][j-1] = 2;
                }
                //right
                if(j+1 < n && grid[i][j+1] == 0) {
                    if(i == n-1 && j+1 == n-1) return ans;
                    q.push(make_pair(i, j+1));
                    grid[i][j+1] = 2;
                }
                // down left
                if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 0) {
                    if(i+1 == n-1 && j-1 == n-1) return ans;
                    q.push(make_pair(i+1, j-1));
                    grid[i+1][j-1] = 2;
                }
                // down
                if(i+1 < n && grid[i+1][j] == 0) {
                    if(i+1 == n-1 && j == n-1) return ans;
                    q.push(make_pair(i+1, j));
                    grid[i+1][j] = 2;
                }
                // down right
                if(i+1 < n && j+1 < n && grid[i+1][j+1] == 0) {
                    if(i+1 == n-1 && j+1 == n-1) return ans;
                    q.push(make_pair(i+1, j+1));
                    grid[i+1][j+1] = 2;
                }
            }
        }
        return -1;
    }
};