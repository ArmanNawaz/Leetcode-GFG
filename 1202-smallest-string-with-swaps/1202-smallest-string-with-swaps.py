class Solution:
    def dfs(self, s, idx):
        self.visited[idx] = True
        
        self.indices.append(idx)
        self.string.append(s[idx])
        
        for nbr in self.adj[idx]:
            if self.visited[nbr] == False:
                self.dfs(s, nbr)
        
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        
        n = len(s)
        self.visited = [False] * n
        self.adj = [list() for _ in range(n)]
        
        self.indices = []
        self.string = []
        
        # Building adjacency list
        for pair in pairs:
            self.adj[pair[0]].append(pair[1])
            self.adj[pair[1]].append(pair[0])
            
        ans = ['-'] * n
        for i in range(n):
            if self.visited[i] == False:
                self.indices = []
                self.string = []
                
                # finding connected components
                self.dfs(s, i)
                
                # Sorting one connected component
                self.indices.sort()
                self.string.sort()
                
                # Arranging the found letters on their indices
                for j in range(len(self.indices)):
                    ans[self.indices[j]] = self.string[j]
                    
        return ''.join(ans)
                
            
        