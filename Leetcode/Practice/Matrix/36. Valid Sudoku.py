class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        m = len(board)
        n = len(board[0])

        # row
        for i in range(m):
            c = Counter()
            for j in range(n):
                if board[i][j] == '.':
                    continue
                c[board[i][j]] += 1
                if c[board[i][j]] > 1:
                    return False
        
        # column
        for j in range(n):
            c = Counter()
            for i in range(m):
                if board[i][j] == '.':
                    continue
                c[board[i][j]] += 1
                if c[board[i][j]] > 1:
                    return False
        
        # 3x3
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                c = Counter()
                for x in range(i, i+3):
                    for y in range(j, j+3):
                        if board[x][y] == '.':
                            continue
                        c[board[x][y]] += 1
                        if c[board[x][y]] > 1:
                            return False
        
        return True