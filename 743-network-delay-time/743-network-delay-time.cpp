class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return solve(times, n, k);
    }
private:
    // Aakash Sir
    // Dijkstra Algorithm
    vector<vector<int>> buildGraph(vector<vector<int>>& times, int n) {
        vector<vector<int>> weight(n + 1, vector<int>(n + 1, -1));
        
        for(auto time: times) {
            int src = time[0];
            int dest = time[1];
            int wt = time[2];
            
            weight[src][dest] = wt;
        }
        return weight;
    }
    
    int solve(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<int>> weight = buildGraph(times, n);
        
        vector<int> distance(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        minHeap.push({0, k});
        distance[k] = 0;
        
        while(!minHeap.empty()) {
            int currDist = minHeap.top().first;
            int currNode = minHeap.top().second;
            
            minHeap.pop();
            
            if(visited[currNode] == false) {
                visited[currNode] = true;
                for(int vertex = 1; vertex <= n; ++vertex) {
                    if(weight[currNode][vertex] != -1) {
                        if(currDist + weight[currNode][vertex] < distance[vertex]) {
                            distance[vertex] = currDist + weight[currNode][vertex];
                            minHeap.push({distance[vertex], vertex});
                        }
                    }
                }
            }
        }
        int ans = INT_MIN;
        
        for(int i = 1; i <= n; ++i) {
            if(distance[i] == INT_MAX)
                return -1;
            ans = max(ans, distance[i]);
        }
        return ans;
    }
};