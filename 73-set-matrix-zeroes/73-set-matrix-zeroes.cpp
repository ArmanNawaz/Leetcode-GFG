class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        return rahulSir(matrix);
        // return optimised(matrix);
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
    // O(m*n) Time and O(m + n) space
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
    
    // O(m*n) Time and O(1) extra space
    void rahulSir(vector<vector<int>>& matrix) {
        int col = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; ++i) {
            if(matrix[i][0] == 0)
                col = 1;
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j > 0; --j) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
            if(col == 1)
                matrix[i][0] = 0;
        }
    }
};