class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = []
        ans = inf
        for i, row in enumerate(triangle):
            dp.append([0 for _ in range(len(row))])
            for j, val in enumerate(row):
                if i == 0:
                    dp[i][j] = val
                else:
                    if j == 0:
                        last_mn = dp[i-1][j]
                    elif j == len(row)-1:
                        last_mn = dp[i-1][j-1]
                    else:
                        last_mn = min(dp[i-1][j], dp[i-1][j-1])
                    dp[i][j] = val + last_mn

                if i == len(triangle)-1:
                    ans = min(ans, dp[i][j])
        
        return ans