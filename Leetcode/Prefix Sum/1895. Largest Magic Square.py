class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cum = [[[0 for _ in range(2)] for _ in range(n)] for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                cum[i][j][0] = cum[i][j-1][0] + grid[i][j]
                cum[i][j][1] = cum[i-1][j][1] + grid[i][j]

        def is_magic(i1: int, j1: int, i2: int, j2: int) -> bool:
            s = cum[i1][j2][0] - (0 if j1 == 0 else cum[i1][j1-1][0])
            
            for i in range(i1+1, i2+1):
                cur_s = cum[i][j2][0] - (0 if j1 == 0 else cum[i][j1-1][0])
                if cur_s != s:
                    return False
            for j in range(j1, j2+1):
                cur_s = cum[i2][j][1] - (0 if i1 == 0 else cum[i1-1][j][1])
                if cur_s != s:
                    return False
            d1_s = d2_s = 0
            i = 0
            while i1+i <= i2:
                d1_s += grid[i1+i][j1+i]
                d2_s += grid[i1+i][j2-i]
                i += 1
            if d1_s != s or d2_s != s:
                return False
            return True

        ans = 1
        for i1 in range(m):
            for j1 in range(n):
                i2, j2 = i1+1, j1+1
                while i2 < m and j2 < n:
                    if is_magic(i1, j1, i2, j2):
                        ans = max(ans, i2-i1+1)
                    i2 += 1
                    j2 += 1
        
        return ans