class Solution:
    def numberOfWays(self, corridor: str) -> int:
        mod = 10**9 + 7
        n = len(corridor)
        dp = [[-1 for _ in range(3)] for _ in range(n)]
        
        def solve(i: int, s: int) -> int:
            if i == n:
                return 1 if s == 2 else 0
            if dp[i][s] != -1:
                return dp[i][s]
            
            res = 0
            if corridor[i] == 'S':
                if s+1 <= 2:
                    res = solve(i+1, s+1)
                elif s == 2:
                    res = solve(i+1, 1)
            else:
                if s == 2:
                    res = (solve(i+1, 2) + solve(i+1, 0)) % mod
                else:
                    res = solve(i+1, s)
            
            dp[i][s] = res
            return dp[i][s]

        return solve(0, 0)