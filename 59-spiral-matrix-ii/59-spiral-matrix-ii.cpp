class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        return solve(n);
    }
private:
    vector<vector<int>> solve(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int r1 = 0, r2 = n - 1;
        int c1 = 0, c2 = n - 1;
        int value = 0;
        
        while(r1 <= r2 && c1 <= c2) {
            
            // Left -> Right
            for(int i = c1; i <= c2; ++i)
                matrix[r1][i] = ++value;
            
            // Up -> Down
            for(int i = r1 + 1; i <= r2; ++i) 
                matrix[i][c2] = ++value;
            
            // Right -> Left
            for(int i = c2 - 1; i > c1; --i) 
                matrix[r2][i] = ++value;
            
            // Down -> Up
            for(int i = r2; i > r1; --i)
                matrix[i][c1] = ++value;
            
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return matrix;
    }
};