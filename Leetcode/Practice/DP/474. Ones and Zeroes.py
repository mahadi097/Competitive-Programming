class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        f = []
        for s in strs:
            f01 = Counter(s)
            f.append([f01['0'], f01['1']])
        
        @cache
        def solve(pos: int, f0: int, f1: int) -> int:
            if pos == len(f):
                return 0
            
            t1 = solve(pos+1, f0, f1)
            t2 = 0
            if f0+f[pos][0] <= m and f1+f[pos][1] <= n:
                t2 = 1 + solve(pos+1, f0+f[pos][0], f1+f[pos][1])

            return max(t1, t2)

        return solve(0, 0, 0) 