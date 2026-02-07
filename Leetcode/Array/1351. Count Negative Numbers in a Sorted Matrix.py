class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        ans = 0
        for row in grid:
            for item in row:
                if item < 0:
                    ans += 1
        return ans