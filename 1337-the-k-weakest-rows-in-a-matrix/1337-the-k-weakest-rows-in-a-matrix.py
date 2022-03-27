class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]: 
        
        mylist = [[mat[i].count(1), i] for i in range(len(mat))]
        mylist.sort(key = lambda x: x[0])
        
        return [mylist[i][1] for i in range(k)]
        