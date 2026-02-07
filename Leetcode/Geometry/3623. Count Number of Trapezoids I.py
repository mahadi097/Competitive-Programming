class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        cy = defaultdict(int)
        mod = 10 ** 9 + 7
        ans = total = 0

        for x, y in points:
            cy[y] += 1

        for y in cy:
            cy[y] = (cy[y] * (cy[y]-1)) // 2
            total = (total + cy[y]) % mod

        for y in cy:
            total = (total - cy[y]) % mod
            ans = (ans + (cy[y] * total)) % mod
        
        return ans