class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        cum = [[0 for _ in range(n)] for _ in range(m)]
    
        for i in range(m):
            for j in range(n):
                cum[i][j] = mat[i][j] + cum[i][j-1] + cum[i-1][j]
                if i > 0 and j > 0:
                    cum[i][j] -= cum[i-1][j-1]

        def is_possible(i: int, j: int, c: int) -> bool:
            s = cum[i+c][j+c]
            if j != 0:
                s -= cum[i+c][j-1]
            if i != 0:
                s -= cum[i-1][j+c]
            if i > 0 and j > 0:
                s += cum[i-1][j-1]
            return s <= threshold
        
        ans = 0
        for i in range(m):
            for j in range(n):
                st, en = ans, min(m-i-1, n-j-1)
                while st <= en:
                    mid = (st + en) // 2
                    if is_possible(i, j, mid):
                        ans = mid + 1
                        st = mid + 1
                    else:
                        en = mid - 1
        return ans