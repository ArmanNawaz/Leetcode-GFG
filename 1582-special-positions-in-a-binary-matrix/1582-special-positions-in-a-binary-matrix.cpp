class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        return bruteForce(mat);
    }
private:
    // O(mn * (m + n)) Time and O(1) extra space
    int bruteForce(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int result = 0;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 1) {
                    int row = 0;
                    while(row < m) {
                        if(row != i && mat[row][j] == 1)
                            break;
                        ++row;
                    }
                    int col = 0;
                    while(col < n) {
                        if(col != j && mat[i][col] == 1)
                            break;
                        ++col;
                    }
                    if(row == m && col == n) ++result;
                }
            }
        }
        return result;
    }
};