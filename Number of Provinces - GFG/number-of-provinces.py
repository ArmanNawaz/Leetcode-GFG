#User function Template for python3

class Solution:
    
    def dfs(self, node, visited, adj, v):
        visited[node] = True
        
        for i in range(v):
            if visited[i] == False and adj[node][i]:
                self.dfs(i, visited, adj, v)

    
    def numProvinces(self, adj, v):
        visited = [False] * v
        ans = 0
        for i in range(v):
            if visited[i] == False:
                self.dfs(i, visited, adj, v)
                ans += 1
        return ans
        
        

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        V=int(input())
        adj=[]
        
        for i in range(V):
            temp = list(map(int,input().split()))
            adj.append(temp);
        
        ob = Solution()
        print(ob.numProvinces(adj,V))
# } Driver Code Ends