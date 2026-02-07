class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        hBars.sort()
        vBars.sort()

        def get_mx_size(bars: List[int]) -> int:
            size, i = 1, 0
            while i < len(bars):
                first_bar = bars[i] - 1
                last_bar = bars[i]
                while i < len(bars) and bars[i] == last_bar:
                    last_bar += 1
                    i += 1
                size = max(size, last_bar-first_bar)
            return size
            
        mx_w = get_mx_size(vBars)
        mx_l = get_mx_size(hBars)
        return min(mx_w, mx_l) * min(mx_w, mx_l)