class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        power.sort()
        n = len(power)
        next_pos = [n] * n
        f = defaultdict(int)

        j = 0
        for i in range(n):
            f[power[i]] += 1
            while j < n and power[j] <= power[i]+2:
                j += 1
            next_pos[i] = j
        
        @cache
        def solve(i: int) -> int:
            if i == n:
                return 0
            d1 = power[i]*f[power[i]] + solve(next_pos[i])
            d2 = solve(i+1)

            return max(d1, d2)
        
        ans = 0
        for i in range(n):
            ans = max(ans, solve(i))

        return ans