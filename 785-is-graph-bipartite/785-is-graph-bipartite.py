class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n
        color[0] = 0
        
        for i in range(n):
            for nbr in graph[i]:
                if color[nbr] == -1:
                    color[nbr] = 1 - color[i]
                
                elif color[i] == color[nbr]:
                    return False
        return True