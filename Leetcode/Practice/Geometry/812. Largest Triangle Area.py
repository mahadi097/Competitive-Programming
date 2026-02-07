class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        
        def get_dis(p1: List[int], p2: List[int]) -> float:
            return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)
        
        def valid_tr(a, b, c) -> bool:
            return a + b > c and a + c > b and b + c > a
        
        def get_area(a, b, c) -> float:
            s = (a + b + c) / 2
            return math.sqrt(s * (s - a) * (s - b) * (s - c))
        
        ans, n = 0, len(points)

        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    a = get_dis(points[i], points[j])
                    b = get_dis(points[j], points[k])
                    c = get_dis(points[k], points[i])
                    
                    if valid_tr(a, b, c):
                        ans = max(ans, get_area(a, b, c))
        
        return round(ans, 5)