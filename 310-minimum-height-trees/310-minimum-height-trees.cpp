class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        return solve(n, edges);
    }
private:
    unordered_map<int, unordered_set<int>> buildGraph(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph(n);
        
        for(auto edge: edges) {
            int x = edge[0];
            int y = edge[1];
            graph[x].insert(y);
            graph[y].insert(x);
        }
        return graph;
    }   
    
    vector<int> solve(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        unordered_map<int, unordered_set<int>> graph = buildGraph(n, edges);
        
        vector<int> ans;
        
        queue<int> q;
        for(auto entry: graph) {
            auto node = entry.first;
            auto nbrs = entry.second;

            if(nbrs.size() == 1) q.push(node);
        }
        vector<int> degree(n, 0);
        
        while(n > 2) {
            
            int size = q.size();
            n -= size;
            
            while(size-- > 0) {
                int curr = q.front();
                q.pop();
                
                int node = *begin(graph[curr]);
                
                graph[node].erase(curr);
                if(graph[node].size() == 1) q.push(node);
                graph.erase(curr);
            }
        }
        for(auto entry: graph) {
            ans.push_back(entry.first);
        }
        
        return ans;
    }
};