class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return daily(grid);
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
    
    int daily(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // base case
        // if cannot go if either source or dest is already 1
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        if(n == 1)
            return 1;
        
        // all possible directions
        vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1},
                                      {0, +1}, {0, -1},
                                      {1, -1}, {1, 0}, {1, 1}};
        
        queue<pair<pair<int, int>, int>> queue;
        queue.push({{0, 0}, 1});  // {{x, y}, length of path to reach x, y}
        int minAns = INT_MAX;
        
        while(!queue.empty()) {
            auto curr = queue.front();
            queue.pop();
            
            // iterate for all directions
            for(int i = 0; i < 8; ++i) {
                int x = curr.first.first + dir[i].first;
                int y = curr.first.second + dir[i].second;
                
                
                if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
                    grid[x][y] = 1;
                    if(x == n - 1 && y == n - 1)
                        minAns = min(minAns, curr.second + 1);
                    queue.push({{x, y}, curr.second + 1});
                }
            }
        }
        return minAns == INT_MAX? -1: minAns;
    }
};