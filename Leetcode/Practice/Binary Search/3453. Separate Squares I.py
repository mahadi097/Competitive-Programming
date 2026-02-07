class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        st, en = 0, 2*(10**9)
        ans = 0
        total_area = 0
        for x, y, l in squares:
            total_area += (l*l)

        def get_down_area(line_y: float) -> float:
            area = 0
            for x, y, l in squares:
                if y < line_y:
                    square_area = (min(y+l, line_y)-y) * l
                    area += square_area
            return area

        while en-st > 10**-5:
            mid = (st + en) / 2
            down_area = get_down_area(mid)
            up_area = total_area - down_area
            if down_area < up_area:
                st = mid
            else:
                ans = mid
                en = mid
        
        return ans