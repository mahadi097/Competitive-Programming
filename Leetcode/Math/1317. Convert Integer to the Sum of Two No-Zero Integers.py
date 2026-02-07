class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:

        def valid(x: int) -> bool:
            while x:
                r = x % 10
                if r == 0: 
                    return False
                x //= 10

            return True

        for x in range(1, n):
            y = n - x

            if valid(x) and valid(y):
                return [x, y]