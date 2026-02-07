class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        time = [[inf for _ in range(n)] for _ in range(n)]
        
        time[0][0] = grid[0][0]
        pq = []
        heapq.heappush(pq, (time[0][0], (0, 0)))

        dirs = [[0, -1], [0, 1], [-1, 0], [1, 0]]

        def valid(i, j) -> bool:
            return i >= 0 and i < n and j >= 0 and j < n
        
        while pq:
            t, (i, j) = heapq.heappop(pq)
            for di, dj in dirs:
                r, c = i+di, j+dj
                if valid(r, c):
                    time_cur = max(time[i][j], grid[r][c])
                    if time_cur < time[r][c]:
                        time[r][c] = time_cur
                        heapq.heappush(pq, (time[r][c], (r, c)))
        
        return time[n-1][n-1]