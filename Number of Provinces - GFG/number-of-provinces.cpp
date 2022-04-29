// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        return solve(adj, V);
    }
  private:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int v, int node) {
        visited[node] = true;
        
        for(int nbr = 0; nbr < v; ++nbr) {
            if(adj[node][nbr] == 1 && visited[nbr] == false)
                dfs(adj, visited, v, nbr);
        }
    }
  
    int solve(vector<vector<int>>& adj, int v) {
        vector<bool> visited(v, false);
        int ans = 0;
        
        for(int i = 0; i < v; ++i) {
            if(visited[i] == false) {
                dfs(adj, visited, v, i);
                ++ans;
            }
        }
        
        return ans;
    }
 
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends