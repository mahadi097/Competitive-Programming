class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        rowOne = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    continue
                if j == 0:
                    rowOne[i][j] = 1
                else:
                    rowOne[i][j] = rowOne[i][j-1] + 1
        
        ans = 0
        for i in range(m):
            for j in range(n):
                mn = rowOne[i][j]
                for k in range(i, -1, -1):
                    mn = min(mn, rowOne[k][j])
                    ans += mn
        
        return ans