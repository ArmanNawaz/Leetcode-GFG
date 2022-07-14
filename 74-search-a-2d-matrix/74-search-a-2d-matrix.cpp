class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0 , high = m * n;
        
        while(low < high){
            int mid = low + (high - low) / 2;
            int i = mid / n, j = mid % n;
            
            if(matrix[i][j] >= target) high = mid;
            else low = mid + 1;
        }
        return (low < m * n && matrix[low / n][low % n] == target);        

    }
};