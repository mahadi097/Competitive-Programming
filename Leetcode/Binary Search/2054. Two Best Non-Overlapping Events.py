class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        n = len(events)
        mx_vals = [0 for _ in range(n+1)]

        events.sort(key=lambda x: x[0])
        
        for i in range(n-1, -1, -1):
            mx_vals[i] = max(events[i][2], mx_vals[i+1])
        
        ans = 0
        for i in range(n):
            cur_sum = events[i][2]
            st, en, j = i+1, n-1, n
            while st <= en:
                mid = (st + en) // 2
                if events[mid][0] > events[i][1]:
                    j = mid
                    en = mid - 1
                else:
                    st = mid + 1
            cur_sum += mx_vals[j]
            ans = max(ans, cur_sum)
        
        return ans