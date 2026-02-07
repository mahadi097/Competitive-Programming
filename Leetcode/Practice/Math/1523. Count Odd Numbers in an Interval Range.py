class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high-low+1) // 2 + (1 if ((high-low+1) & 1 == 1 and low & 1 == 1) else 0)