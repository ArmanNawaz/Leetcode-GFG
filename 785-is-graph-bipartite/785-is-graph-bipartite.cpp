class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        return solve(graph);
    }
private:
    bool solve(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        color[0] = 0;
        for(int i = 0; i < n ; i++) {
            for(auto x : graph[i]) {
                if(color[x] == -1)
                    color[x] = 1 - color[i];
                
                else if(color[x] == color[i])
                      return false;
            }
        }
        return true;
    }
};