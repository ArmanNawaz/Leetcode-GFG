class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        return optimised(matrix);
        // return bruteForce(matrix);
    }
private:
    // O(mn * (m + n)) Time and O(mn) extra space
    void bruteForce(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        auto copy = matrix; // O(mn) Time
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(copy[i][j] == 0) {
                    for(int row = 0; row < m; ++row) matrix[row][j] = 0;
                    for(int col = 0; col < n; ++col) matrix[i][col] = 0;
                }
            }
        }
        return;
    }
    
    void optimised(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<bool> rows(m, false), cols(n, false);
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        
        for(int i = 0; i < m; ++i) {
            if(rows[i]) {
                for(int j = 0; j < n; ++j) 
                    matrix[i][j] = 0;
            }
        }
        for(int j = 0; j < n; ++j) {
            if(cols[j]) {
                for(int i = 0; i < m; ++i) 
                    matrix[i][j] = 0;
            }
        }
        
        return;
    }
};