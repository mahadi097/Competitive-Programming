class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m = len(heights)
        n = len(heights[0])
        ocean = [[[False for _ in range(2)] for _ in range(n)] for _ in range(m)]

        directions = [[0, -1], [-1, 0], [0, 1], [1, 0]]

        def valid(i, j) -> bool:
            return i >= 0 and i < m and j >= 0 and j < n

        def bfs(o):
            cells = deque()
            visited = defaultdict(bool)
            
            if o == 0:
                for j in range(n):
                    visited[(0, j)] = True
                    cells.append([0, j])
                    ocean[0][j][0] = True
                for i in range(1, m):
                    visited[(i, 0)] = True
                    cells.append([i, 0])
                    ocean[i][0][0] = True
            else:
                for j in range(n):
                    visited[(m-1, j)] = True
                    cells.append([m-1, j])
                    ocean[m-1][j][1] = True
                for i in range(0, m-1):
                    visited[(i, n-1)] = True
                    cells.append([i, n-1])
                    ocean[i][n-1][1] = True

            while cells:
                i, j = cells.popleft()
                for di, dj in directions:
                    r, c = i+di, j+dj
                    if valid(r, c) and heights[r][c] >= heights[i][j] and not visited[(r, c)]:
                        visited[(r, c)] = True
                        ocean[r][c][o] = True
                        cells.append([r, c])
        
        bfs(0)
        bfs(1)

        res = []
        for i in range(m):
            for j in range(n):
                if ocean[i][j][0] and ocean[i][j][1]:
                    res.append([i, j])
        
        return res