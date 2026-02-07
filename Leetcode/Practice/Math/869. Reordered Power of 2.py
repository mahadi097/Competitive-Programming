class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        def numToSortedString(x: int):
            s = str(x)
            sortedS = "".join(sorted(s))
            return sortedS

        
        x = 1
        while x <= 1e9:
            sX = numToSortedString(x)
            sN = numToSortedString(n)

            if sX == sN: return True

            x *= 2
        
        return False