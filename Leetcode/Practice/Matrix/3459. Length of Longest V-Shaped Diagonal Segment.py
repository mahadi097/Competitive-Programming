class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        segs = [[[0 for _ in range(4)] for _ in range(n)] for _ in range(m)]
        turn90 = {0: 2, 1: 3, 2: 1, 3: 0}
        dirs = [[1, 1], [-1, -1], [1, -1], [-1, 1]] #directions

        def valid(i: int, j: int, nextEl: int) -> bool:
            return i >= 0 and i < m and j >= 0 and j < n and grid[i][j] == nextEl

        def cal_segs(i: int, j: int, k: int, nextEl: int) -> int:
            if valid(i, j, nextEl) == False: 
                return 0
            if segs[i][j][k]: return segs[i][j][k]
            
            segs[i][j][k] = 1 + cal_segs(i+dirs[k][0], j+dirs[k][1], k, 0 if grid[i][j] == 2 else 2)
            return segs[i][j][k]
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 or grid[i][j] == 2:
                    for k in range(4):
                        cal_segs(i, j, k, grid[i][j])
        
        dp = [[[0 for _ in range(4)] for _ in range(n)] for _ in range(m)]

        def max_seg(i: int, j: int, k: int, nextEl: int) -> int:
            if valid(i, j, nextEl) == False:
                return 0
            
            dp[i][j][k] = max(segs[i][j][k], segs[i][j][turn90[k]], 1 + max_seg(i+dirs[k][0], j+dirs[k][1], k, 0 if grid[i][j] == 2 else 2))
            return dp[i][j][k]

        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    for k in range(4):
                        r = i + dirs[k][0]
                        c = j + dirs[k][1]
                        ans = max(ans, 1 + max_seg(r, c, k, 2))

        return ans