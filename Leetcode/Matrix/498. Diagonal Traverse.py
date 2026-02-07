class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        ans = []
        m = len(mat)
        n = len(mat[0])

        def isValid(i: int, j: int) -> bool:
            return i >= 0 and i < m and j >= 0 and j < n

        def isEnd(i: int, j: int) -> bool:
            return i == m-1 and j == n-1
        
        r = 0
        c = 0
        while True:
            while True:
                ans.append(mat[r][c])
                if isValid(r-1, c+1):
                    r -= 1
                    c += 1
                else:
                    break
            
            if isEnd(r, c):
                break
            
            if isValid(r, c+1):
                c += 1
            else:
                r += 1
            
            while True:
                ans.append(mat[r][c])
                if isValid(r+1, c-1):
                    r += 1
                    c -= 1
                else:
                    break
            
            if isEnd(r, c):
                break
            
            if isValid(r+1, c):
                r += 1
            else:
                c += 1
        
        return ans