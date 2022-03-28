class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return solve(matrix);
    }
private:
    vector<int> solve(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int numberOfElements = n * m;
        vector<int> ans;
        int i = 0, j = 0;
        
        while(numberOfElements > 0) {
            int newM = n - i;
            int newN = m - j;
            int row = i;
            int col = j;
            
            while(col < newN && numberOfElements > 0) {
                ans.push_back(matrix[row][col]);
                --numberOfElements;
                ++col;
            }
            --col;
            ++row;
            
            while(row < newM && numberOfElements > 0) {
                ans.push_back(matrix[row][col]);
                --numberOfElements;
                ++row;
            }            
            --row;
            --col;
            
            while(col >= i && numberOfElements > 0) {
                ans.push_back(matrix[row][col]);
                --numberOfElements;
                --col;
            }
            ++col;
            --row;
            
            while(row > j && numberOfElements > 0) {
                ans.push_back(matrix[row][col]);
                --numberOfElements;
                --row;
            }
            i += 1;
            j += 1;
        }
        return ans;
    }
};