class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        c = 0
        while numBottles != 0:
            drank = min(numBottles, numExchange)
            numBottles -= drank
            if drank == numExchange:
                numBottles += 1
                numExchange += 1
            c += drank
        
        return c