class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)
        dp = [[[-1 for _ in range(3)] for _ in range(k+1)] for _ in range(n)]
        
        def solve(i: int, t: int, t_type: int) -> int:
            if i == n:
                return 0 if t_type == 0 else -inf
            if dp[i][t][t_type] != -1:
                return dp[i][t][t_type]
            res = 0
            if t_type == 0:
                res = solve(i+1, t, 0)
                if t+1 <= k:
                    r1 = -prices[i] + solve(i+1, t, 2)
                    r2 = prices[i] + solve(i+1, t, 1)
                    res = max(res, r1, r2)
            elif t_type == 1:
                res = max(solve(i+1, t, 1), -prices[i]+solve(i+1, t+1, 0))
            else:
                res = max(solve(i+1, t, 2), prices[i]+solve(i+1, t+1, 0))
            dp[i][t][t_type] = res
            return dp[i][t][t_type]
        
        return solve(0, 0, 0)