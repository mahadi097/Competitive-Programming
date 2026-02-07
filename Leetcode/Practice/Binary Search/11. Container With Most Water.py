class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans, n = 0, len(height)
        mx = [[0 for _ in range(2)] for _ in range(n)]

        for i in range(n):
            mx[i][0] = height[i] if i == 0 else max(height[i], mx[i-1][0])
        
        for i in range(n-1, -1, -1):
            mx[i][1] = height[i] if i == n-1 else max(height[i], mx[i+1][1])

        for i in range(n):
            st, en, pos = 0, i, i
            while st <= en:
                mid = (st + en) // 2
                if mx[mid][0] >= height[i]:
                    pos = mid
                    en = mid - 1
                else:
                    st = mid + 1

            area = (i - pos) * height[i]
            ans = max(ans, area)

            st, en, pos = i, n-1, i
            while st <= en:
                mid = (st + en) // 2
                if mx[mid][1] >= height[i]:
                    pos = mid
                    st = mid + 1
                else:
                    en = mid - 1
            
            area = (pos - i) * height[i]
            ans = max(ans, area)
        
        return ans