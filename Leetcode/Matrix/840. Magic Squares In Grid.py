class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0

        for i in range(m-2):
            for j in range(n-2):
                nums = set()
                is_magic = True
                for r in range(i, i+3):
                    sr = 0
                    for c in range(j, j+3):
                        if grid[r][c] < 1 or grid[r][c] > 9:
                            is_magic = False
                        nums.add(grid[r][c])
                        sr += grid[r][c]
                    if sr != 15:
                        is_magic = False
                for c in range(j, j+3):
                    sc = grid[i][c] + grid[i+1][c] + grid[i+2][c]
                    if sc != 15:
                        is_magic = False
                sd1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]
                sd2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j]
                if sd1 != 15 or sd2 != 15 or len(nums) != 9:
                    is_magic = False
                if is_magic:
                    ans += 1
        
        return ans