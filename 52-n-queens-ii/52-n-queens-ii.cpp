class Solution {
public:
    int totalNQueens(int n) {
        return solve(n);
    }
private:
    unordered_set<int> index, diag, antiDiag;
    
    bool isValidMove(int i, int j) {
        if(index.find(j) != index.end()) return false;
        if(diag.find(i + j) != diag.end()) return false;
        if(antiDiag.find(i - j)  != antiDiag.end()) return false;
        
        return true;
    }
    void backtrack(int i, int n, int& validCounts, int& count) {
        
        if(i >= n) {
            if(validCounts == n)
                ++count;
            return;
        }
        
        for(int j = 0; j < n; ++j) {
            if(isValidMove(i, j)) {
                index.insert(j);
                diag.insert(i + j);
                antiDiag.insert(i - j);
                ++validCounts;
                backtrack(i + 1, n, validCounts, count);
                
                // backtrack
                --validCounts;
                index.erase(j);
                diag.erase(i + j);
                antiDiag.erase(i - j);
            }
        }
        
    }
    
    
    int solve(int n) {
        int count = 0;
        int validCounts = 0;
        backtrack(0, n, validCounts, count);
        return count;
    }
};