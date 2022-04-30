class Solution:
    def dfs(self, curr, value):
            
        if curr == self.target:
            return value

        for adj, adj_value in self.graph[curr].items():
            if adj not in self.visited:
                self.visited.add(adj)
                result = self.dfs(adj, value * adj_value)  # orig/adj = (orig/curr) * (curr/adj) = value*adj_value
                if result != -1:
                    return result
                self.visited.remove(adj)  # backtrack
        return -1
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        
        self.graph = defaultdict(dict)
        self.visited = set()  # all visited expressions
        for (a, b), value in zip(equations, values):
            self.graph[a][b] = value  # a/b = value, given
            self.graph[b][a] = 1/value  # b/a = 1/(a/b) = 1/value
        result = []
        
        for x, y in queries:
            self.target = y
            if x in self.graph:
                result.append(self.dfs(x, 1))
            else:
                result.append(-1)
            self.visited.clear()
        return result