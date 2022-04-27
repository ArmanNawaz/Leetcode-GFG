class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        return solve(s, pairs);
    }
private:
    int n;
    vector<bool> visited;
    vector<int> indices;
    string str = "";
    vector<vector<int>> adj;
    
    void dfs(string& s, int idx) {
        visited[idx] = true;
        
        indices.push_back(idx);
        str += s[idx];
        
        for(auto nbr: adj[idx]) {
            if(visited[nbr] == false)
                dfs(s, nbr);
        }
    }
    
    string solve(string s, vector<vector<int>>& pairs) {
        n = s.length();
        visited.resize(this -> n, false);
        adj.resize(this -> n);
        for(auto pair: pairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                str = "";
                indices.clear();
                
                dfs(s, i);
                
                sort(str.begin(), str.end());
                sort(indices.begin(), indices.end());
                
                for(int j = 0; j < indices.size(); ++j) {
                    s[indices[j]] = str[j];
                }
            }
        }
        return s;
    }
};