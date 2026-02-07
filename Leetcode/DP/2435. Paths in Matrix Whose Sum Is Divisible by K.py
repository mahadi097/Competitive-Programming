class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[[0 for _ in range(k)] for _ in range(n)] for _ in range(m)]
        mod = 10**9 + 7
        
        dp[0][0][grid[0][0]%k] = 1
        for i in range(m):
            for j in range(n):
                if i-1 >= 0:
                    for kk in range(k):
                        v = (kk + grid[i][j]) % k
                        dp[i][j][v] = (dp[i][j][v] + dp[i-1][j][kk]) % mod
                if j-1 >= 0:
                    for kk in range(k):
                        v = (kk + grid[i][j]) % k
                        dp[i][j][v] = (dp[i][j][v] + dp[i][j-1][kk]) % mod
        
        return dp[m-1][n-1][0]