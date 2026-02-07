class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        row = [[inf, 0] for _ in range(n+1)]
        col = [[inf, 0] for _ in range(n+1)]
        
        for x, y in buildings:
            row[x][0] = min(row[x][0], y)
            row[x][1] = max(row[x][1], y)
            col[y][0] = min(col[y][0], x)
            col[y][1] = max(col[y][1], x)
        
        ans = 0
        for x, y in buildings:
            if row[x][0] < y and row[x][1] > y and col[y][0] < x and col[y][1] > x:
                ans += 1
        
        return ans