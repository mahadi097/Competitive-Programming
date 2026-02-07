class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        min_time = 0
        for i in range(1, len(points)):
            x1, y1 = points[i-1]
            x2, y2 = points[i]
            x, y = (x2 - x1), (y2 - y1)
            x11 = (x1 + abs(y)) if x2 > x1 else (x1 - abs(y))
            y11 = (y1 + abs(x)) if y2 > y1 else (y1 - abs(x))
            
            t1 = abs(x) + abs(y11 - y2)
            t2 = abs(y) + abs(x11 - x2)
            min_time += min(t1, t2)
        
        return min_time