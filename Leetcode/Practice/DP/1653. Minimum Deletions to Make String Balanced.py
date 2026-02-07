class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        dp = [[-1 for _ in range(2)] for _ in range(n)]

        def solve(i: int, b: int) -> int:
            if i == n:
                return 0
            if dp[i][b] != -1:
                return dp[i][b]
            
            res = 0
            if s[i] == 'a':
                if b:
                    res = 1 + solve(i+1, 1)
                else:
                    res = solve(i+1, 0)
            else:
                if b:
                    res = solve(i+1, 1)
                else:
                    res = min(1 + solve(i+1, 0), solve(i+1, 1))
            dp[i][b] = res
            return dp[i][b]

        return solve(0, 0)