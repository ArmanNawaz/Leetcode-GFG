class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        return bruteForce(matrix, k);
        // return channaSir(matrix, k);
    }
private:
    int bruteForce(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> res;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                res.push_back(matrix[i][j]);
            }
        }
        sort(res.begin(), res.end());
        return res[k - 1];
    }
    
};