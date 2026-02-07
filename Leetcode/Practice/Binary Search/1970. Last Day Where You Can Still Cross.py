class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        mat = [[0 for _ in range(col)] for _ in range(row)]
        ans = 0
        vis = [[False for _ in range(col)] for _ in range(row)]

        def valid_cell(i: int, j: int) -> bool:
            return i >= 0 and i < row and j >= 0 and j < col

        def dfs(i: int, j: int) -> None:
            if not valid_cell(i, j) or vis[i][j] or mat[i][j] == 1:
                return
            vis[i][j] = 1

            dfs(i, j-1)
            dfs(i, j+1)
            dfs(i-1, j)
            dfs(i+1, j)

        def possible(last_day: int) -> bool:
            for i in range(row):
                for j in range(col):
                    mat[i][j] = 0
                    vis[i][j] = False
            for i in range(last_day):
                x, y = cells[i]
                mat[x-1][y-1] = 1

            for j in range(col):
                dfs(0, j)

            for j in range(col):
                if vis[row-1][j]:
                    return True
            return False

        st, en = 1, row*col
        while st <= en:
            mid = (st + en) // 2
            if possible(mid):
                ans = mid
                st = mid + 1
            else:
                en = mid - 1
        
        return ans