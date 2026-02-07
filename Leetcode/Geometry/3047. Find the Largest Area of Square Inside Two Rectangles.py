class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        ans, n = 0, len(bottomLeft)
        for i in range(n):
            x1_bl, y1_bl = bottomLeft[i]
            x1_tr, y1_tr = topRight[i]
            for j in range(i+1, n):
                x2_bl, y2_bl = bottomLeft[j]
                x2_tr, y2_tr = topRight[j]
                x_ln = min(x1_tr, x2_tr) - max(x1_bl, x2_bl)
                y_ln = min(y1_tr, y2_tr) - max(y1_bl, y2_bl)
                ans = max(ans, min(x_ln, y_ln))
        ans **= 2
        return ans