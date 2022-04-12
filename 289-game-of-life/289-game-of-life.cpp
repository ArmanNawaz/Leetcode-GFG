class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
     return solve(board);   
    }
private:
    void solve(vector<vector<int>>& board) {
        int m = board[0].size();
        int n = board.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cnt = 0;
                
                // vertical and horizontal
                if(i > 0 && board[i - 1][j] >= 1) cnt++;
                if(i < n - 1 && board[i + 1][j] >= 1) cnt++; 
                if(j > 0 && board[i][j - 1] >= 1) cnt++; 
                if(j < m - 1 && board[i][j + 1] >= 1) cnt++;
                
                // diagonally
                if(i > 0 && j > 0 && board[i - 1][j - 1] >= 1) cnt++; 
                if(i > 0 && j < m - 1 && board[i - 1][j + 1] >= 1) cnt++; 
                if(i < n - 1 && j > 0 && board[i + 1][j - 1] >= 1) cnt++; 
                if(i < n - 1 && j < m - 1 && board[i + 1][j + 1] >= 1) cnt++; 
                
                
                if(board[i][j] == 1 && (cnt < 2 || cnt > 3)) board[i][j] = 2;
                
                if(board[i][j] == 0 && cnt == 3) board[i][j] = -1;
            }
        }
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 2) board[i][j] = 0;
                if(board[i][j] == -1) board[i][j] = 1;
            }
        }
            
        return;
    }
};