class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])

        def valid(i: int, j: int) -> bool:
            return i >= 0 and i < m and j >= 0 and j < n
        
        i = 0
        while i < m:
            x = i
            y = 0
            d = []
            while valid(x, y):
                d.append(grid[x][y])
                x += 1
                y += 1
            
            d.sort(reverse=True)
            x = i
            y = 0
            pos = 0
            while valid(x, y):
                grid[x][y] = d[pos]
                x += 1
                y += 1
                pos += 1
            
            i += 1
        
        j = 1
        while j < n:
            x = 0
            y = j
            d = []
            while valid(x, y):
                d.append(grid[x][y])
                x += 1
                y += 1
            
            d.sort()
            x = 0
            y = j
            pos = 0
            while valid(x, y):
                grid[x][y] = d[pos]
                x += 1
                y += 1
                pos += 1

            j += 1
        
        return grid