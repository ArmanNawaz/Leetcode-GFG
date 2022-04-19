class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        return bruteForce(matrix);
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
};