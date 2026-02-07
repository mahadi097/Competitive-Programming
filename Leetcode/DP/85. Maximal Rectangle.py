class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        cum = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n-1, -1, -1):
                if j == n-1:
                    cum[i][j] = int(matrix[i][j])
                else:
                    cum[i][j] = 0 if matrix[i][j] == '0' else int(matrix[i][j]) + cum[i][j+1]
        
        ans = 0
        for i in range(m):
            for j in range(n):
                width = cum[i][j]
                for k in range(i, m):
                    width = min(width, cum[k][j])
                    ans = max(ans, (k-i+1)*width)
        
        return ans