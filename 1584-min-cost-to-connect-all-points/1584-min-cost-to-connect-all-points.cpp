class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        return solve(points);
    }
private:
    // Daily
    int solve(vector<vector<int>>& points) {
        int n = points.size();
        int i = 0, ans = 0, cp = 0; // cp- connected points
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>> minHeap;
        
        while(++cp < n) {
            visited[i] = true;
            for(int j = 0; j < n; ++j) {
                if(!visited[j]) {
                    int dist = abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0]);
                    minHeap.push({-dist, j});
                }
            }
            while(visited[minHeap.top().second])
                minHeap.pop();
            ans -= minHeap.top().first;
            i = minHeap.top().second;
            minHeap.pop();
        }
        return ans;
    }
};