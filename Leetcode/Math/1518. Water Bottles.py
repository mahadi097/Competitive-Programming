class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        c = empty = 0
        while numBottles != 0:
            c += numBottles
            empty += numBottles
            numBottles = empty // numExchange
            empty %= numExchange

        return c