from math import sqrt

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for i in range(int(sqrt(c)) + 1):
            jj = c - i*i
            j = int(sqrt(jj))

            if j*j == jj and (i*i + j*j) == c:
                return True
            
        return False
        