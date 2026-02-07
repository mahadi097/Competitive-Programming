class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        def possible(m: int) -> bool:
            c, t = 0, 0
            for b in batteries:
                bm = min(b, m)
                need = m - t
                if bm >= need:
                    c += 1
                    t = bm - need
                else:
                    t += bm
            if t >= m:
                c += 1
            return c >= n

        st, en = 1, sum(batteries) // n
        ans = 0
        while st <= en:
            mid = (st + en) // 2
            if possible(mid):
                ans = mid
                st = mid + 1
            else:
                en = mid - 1
        
        return ans