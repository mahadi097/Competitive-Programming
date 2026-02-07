class Solution:
    def numberOfWays(self, corridor: str) -> int:
        mod = 10**9 + 7
        n = len(corridor)
        total_seats = corridor.count('S')
        if not total_seats or (total_seats & 1):
            return 0

        ans = 1
        s = p = 0
        for item in corridor:
            if item == 'S':
                if s == 2:
                    ans = (ans * (p + 1)) % mod
                    s = 1
                    p = 0
                else:
                    s += 1
                    p = 0
            else:
                p += 1
        return ans