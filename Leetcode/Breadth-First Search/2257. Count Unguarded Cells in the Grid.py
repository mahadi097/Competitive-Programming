class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [['.' for _ in range(n)] for _ in range(m)]
        for i, j in guards:
            grid[i][j] = 'G'
        for i, j in walls:
            grid[i][j] = 'W'
        
        visited = [[[False for _ in range(4)] for _ in range(n)] for _ in range(m)]

        def valid(i: int, j: int, d: int) -> bool:
            if i < 0 or i >= m or j < 0 or j >= n:
                return False
            if d == 0 or d == 2:
                if visited[i][j][0] or visited[i][j][2]:
                    return False
            if d == 1 or d == 3:
                if visited[i][j][1] or visited[i][j][3]:
                    return False
            if grid[i][j] == 'W' or grid[i][j] == 'G':
                return False
            return True 
        
        def get_direction(i: int, j: int, d: int) -> List[int]:
            if d == 0:
                return [i-1, j]
            elif d == 1:
                return [i, j+1]
            elif d == 2:
                return [i+1, j]
            else:
                return [i, j-1]

        def guarded(i: int, j: int) -> bool:
            if grid[i][j] == 'W' or grid[i][j] == 'G':
                return True
            for d in range(4):
                if visited[i][j][d]:
                    return True
            return False

        q = deque()
        for i, j in guards:
            for d in range(4):
                q.append([i, j, d])
        
        while q:
            i, j, d = q.popleft()
            x, y = get_direction(i, j, d)
            if valid(x, y, d):
                visited[x][y][d] = True
                q.append([x, y, d])
        
        ans = 0
        for i in range(m):
            for j in range(n):
                if not guarded(i, j):
                    ans += 1
        
        return ans