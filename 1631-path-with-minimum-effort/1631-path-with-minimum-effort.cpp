class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        return solve(heights);
    }
private:
    // Daily
    int solve(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        
        // All four directions
        vector<int> dir = {0, -1, 0, 1, 0};
        
        // Stores effort for reaching a cell from (0, 0)
        vector<vector<int>> effort(row, vector<int>(col, INT_MAX));
        
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        effort[0][0] = 0;
        
        while(!queue.empty()) {
            auto currCell = queue.front();
            queue.pop();
            
            // iterate for all directions
            for(int i = 0; i < 4; ++i) {
                int x = currCell.first + dir[i];
                int y = currCell.second + dir[i + 1];
                
                // if index is not feasible
                if(x < 0 || y < 0 || x >= row || y >= col)
                    continue;
                
                // if we have already less effort
                if(effort[x][y] <= effort[currCell.first][currCell.second])
                    continue;
                
                // Calculate cell difference for currCell and its adjacent cells
                int cellDiff = abs(heights[x][y] - heights[currCell.first][currCell.second]);
                
                // Maximum route effort
                int routeEffort = max(effort[currCell.first][currCell.second], cellDiff);
                
                effort[x][y] = min(effort[x][y], routeEffort);
                
                // push the adjacent cell to queue
                queue.push({x, y});
            }
        }
        return effort[row - 1][col - 1];
    }
};