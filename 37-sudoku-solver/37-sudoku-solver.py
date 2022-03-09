class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        
        def find_box_index(row, col):
            return (row // 3) * 3 + col // 3
        
        def save_number(digit, row, col):
            rows[row][digit] += 1
            cols[col][digit] += 1
            boxes[find_box_index(row, col)][digit] += 1
        
        def can_be_placed(digit, row, col):
            if digit not in rows[row] and digit not in cols[col] and digit not in boxes[find_box_index(row, col)]:
                return True
            return False
        
        def place_next_number(row, col):
            if row == N - 1 and col == N - 1:
                # print(board)
                nonlocal sudoku_solved
                sudoku_solved = True
            else:
                if col == N - 1:
                    backtrack(row + 1, 0)
                else:
                    backtrack(row, col + 1)
        
        def backtrack(row, col):
            if board[row][col] == ".":
                for d in range(1, N+1):
                    if can_be_placed(d, row, col):
                        save_number(d, row, col)
                        board[row][col] = str(d)
                        place_next_number(row, col)
                        if not sudoku_solved:
                            board[row][col] = "."
                            del rows[row][d]
                            del cols[col][d]
                            del boxes[find_box_index(row, col)][d]
                    
                
            else:
                place_next_number(row, col)
            

        sudoku_solved = False
        N = 9
        rows = [defaultdict(int) for i in range(N)]
        cols = [defaultdict(int) for i in range(N)]
        boxes = [defaultdict(int) for i in range(N)]
        
        for i in range(N):
            for j in range(N):
                if board[i][j] != '.':
                    digit = int(board[i][j])
                    save_number(digit, i, j)
        backtrack(0, 0)
        