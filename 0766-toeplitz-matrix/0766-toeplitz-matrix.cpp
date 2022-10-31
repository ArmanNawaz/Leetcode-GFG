class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(m == 1 && n == 1) return true;
        
        for(int gap = 0; gap < n; ++gap) {
            int i = 0, j = gap;
            int top = matrix[i][j];
            
            while(i < m && j < n) {
                if(matrix[i][j] != top) return false;
                ++i;
                ++j;
            }
        }
        
        for(int gap = 1; gap < m; ++gap) {
            int i = gap, j = 0;
            int top = matrix[i][j];
            
            while(i < m && j < n) {
                if(matrix[i][j] != top) return false;
                ++i;
                ++j;
            }
        }
            
        return true;
    }
};