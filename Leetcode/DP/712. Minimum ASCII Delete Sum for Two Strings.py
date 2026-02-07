class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n1, n2 = len(s1), len(s2)
        dp = [[-1 for _ in range(n2)] for _ in range(n1)]
        cum1, cum2 = [0] * (n1+1), [0] * (n2+1)

        for i in range(n1-1, -1, -1):
            cum1[i] = cum1[i+1] + ord(s1[i])
        for i in range(n2-1, -1, -1):
            cum2[i] = cum2[i+1] + ord(s2[i])

        def solve(i: int, j: int) -> int:
            if i == n1:
                return cum2[j]
            if j == n2:
                return cum1[i]
            if dp[i][j] != -1:
                return dp[i][j]
            
            res = 0
            if s1[i] == s2[j]:
                res = solve(i+1, j+1)
            else:
                res = min(ord(s1[i]) + solve(i+1, j), ord(s2[j]) + solve(i, j+1))
            
            dp[i][j] = res
            return dp[i][j]
        
        return solve(0, 0)