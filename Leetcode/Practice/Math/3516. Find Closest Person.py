class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        dx = abs(x-z)
        dy = abs(y-z)
        if dx < dy:
            return 1
        elif dy < dx:
            return 2
        return 0