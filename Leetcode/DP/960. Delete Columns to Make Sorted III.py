class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        m, n = len(strs), len(strs[0])
        dp = [[-1 for _ in range(n)] for _ in range(n)]

        def solve(pos: int, pos_last: int) -> int:
            if pos == n:
                return 0
            if dp[pos][pos_last] != -1:
                return dp[pos][pos_last]
            
            res = 1 + solve(pos+1, pos_last)
            ok = True
            for i in range(m):
                if strs[i][pos_last] > strs[i][pos]:
                    ok = False
                    break
            if ok:
                res = min(res, solve(pos+1, pos))

            dp[pos][pos_last] = res
            return dp[pos][pos_last]
            
        ans = inf
        for i in range(n):
            ans = min(ans, i + solve(i+1, i))
        
        return ans