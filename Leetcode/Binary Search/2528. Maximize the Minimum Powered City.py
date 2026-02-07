class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        n = len(stations)
        powers = [0] * n
        cum = [0] * n
        
        for i in range(n):
            cum[i] = stations[i] if i == 0 else cum[i-1] + stations[i]
        
        for i in range(n):
            st, en = max(0, i-r), min(n-1, i+r)
            powers[i] = cum[en] - (0 if st == 0 else cum[st-1])

        def possible_min(mn: int) -> bool:
            failed = []
            for i in range(n):
                if powers[i] < mn:
                    failed.append(i)

            pos, rem = 0, k
            cur_st, extra_pow = deque(), 0

            while pos < len(failed) and rem >= 0:
                while len(cur_st) > 0 and abs(cur_st[0][0] - failed[pos]) > r:
                    extra_pow -= cur_st.popleft()[1]
                if powers[failed[pos]] + extra_pow < mn:
                    need_more = mn - (powers[failed[pos]] + extra_pow)
                    cur_st.append([min(n-1, failed[pos]+r), need_more])
                    extra_pow += need_more
                    rem -= need_more
                pos += 1

            return rem >= 0

        st, en = min(stations), cum[n-1] + k
        ans = st
        while st <= en:
            mid = (st + en) // 2
            if possible_min(mid):
                ans = mid
                st = mid + 1
            else:
                en = mid - 1
        
        return ans