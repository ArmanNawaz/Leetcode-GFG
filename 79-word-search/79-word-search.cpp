class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    char ch = board[i][j];
                    board[i][j] = '#';
                    search(board, i, j, word, 1);
                    board[i][j] = ch;
                }
            }
        }                           
        return ans;
    }
private:
    bool ans = false;
    void search(vector<vector<char>>&board, int i, int j, string &word, int idx) {
        // Base Case
		if (idx == word.size()) {
            ans = true;
            return;
        }        
		// Check Right
        if (j + 1 < board[i].size() && board[i][j + 1] == word[idx]) {
            char ch = board[i][j + 1];
            board[i][j + 1] = '#';
            search(board, i, j + 1, word, idx + 1);
            board[i][j + 1] = ch;
        }
		// Check Left
        if (j - 1 >= 0 && board[i][j - 1] == word[idx]) {
            char ch = board[i][j - 1];
            board[i][j - 1] = '#';
            search(board, i, j - 1, word, idx + 1);
            board[i][j - 1] = ch;
        }
		// Check Down
        if (i + 1 < board.size() && board[i + 1][j] == word[idx]) {
            char ch = board[i + 1][j];
            board[i + 1][j] = '#';
            search(board, i + 1, j, word, idx + 1);
            board[i + 1][j] = ch;
        }
		// Check Up
        if (i - 1 >= 0 && board[i - 1][j] == word[idx]) {
            char ch = board[i - 1][j];
            board[i - 1][j] = '#';
            search(board, i - 1, j, word, idx + 1);
            board[i - 1][j] = ch;
        }
    }
};