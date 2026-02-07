class Solution:
    def numOfWays(self, n: int) -> int:
        mod = 10**9 + 7
        dp = {}

        def solve(pos: int, prv: str) -> int:
            if pos == n:
                return 1
            if (pos, prv) in dp:
                return dp[(pos, prv)]
            
            res = 0
            for i in range(1, 4):
                if prv[0] == str(i):
                    continue
                for j in range(1, 4):
                    if prv[1] == str(j) or str(i) == str(j):
                        continue
                    for k in range(1, 4):
                        if prv[2] == str(k) or str(j) == str(k):
                            continue
                        now = str(i) + str(j) + str(k)
                        res = (res + solve(pos+1, now)) % mod
            
            dp[(pos, prv)] = res
            return dp[(pos, prv)]

        return solve(0, '000')