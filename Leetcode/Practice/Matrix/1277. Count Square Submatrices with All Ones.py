class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])

        sq = [[0 for _ in range(n)] for _ in range(m)]
        rowOne = [[0 for _ in range(n)] for _ in range(m)]
        colOne = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 1:
                    if j == 0:
                        rowOne[i][j] = 1
                    else:
                        rowOne[i][j] = rowOne[i][j-1] + 1
        
        for j in range(n):
            for i in range(m):
                if matrix[i][j] == 1:
                    if i == 0:
                        colOne[i][j] = 1
                    else:
                        colOne[i][j] = colOne[i-1][j] + 1
        
        ans = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    continue
                
                if i == 0 or j == 0:
                    sq[i][j] = 1
                else:
                    if sq[i-1][j-1] == 0:
                        sq[i][j] = 1
                    else:
                        mnSq = min(rowOne[i][j], colOne[i][j])
                        if mnSq <= sq[i-1][j-1]:
                            sq[i][j] = mnSq
                        else:
                            sq[i][j] = sq[i-1][j-1] + 1
                ans += sq[i][j]

        return ans