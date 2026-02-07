class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        stP = [0 for _ in range(2)]
        enP = [0 for _ in range(2)]

        m = len(grid)
        n = len(grid[0])

        found = False
        for j in range(n):
            for i in range(m):
                if grid[i][j] == 1:
                    stP[0] = i
                    stP[1] = j
                    found = True
                    break
            if found:
                break
        
        found = False
        for i in range(stP[0]):
            for j in range(n):
                if grid[i][j] == 1:
                    stP[0] = i
                    found = True
                    break
            if found:
                break
        
        found = False
        for j in range(n-1, -1, -1):
            for i in range(m-1, -1, -1):
                if grid[i][j] == 1:
                    enP[0] = i
                    enP[1] = j
                    found = True
                    break
            if found:
                break
        
        found = False
        for i in range(m-1, enP[0], -1):
            for j in range(n):
                if grid[i][j] == 1:
                    enP[0] = i
                    found = True
                    break
            if found:
                break
        
        area = (enP[0] - stP[0] + 1) * (enP[1] - stP[1] + 1)
        return area

