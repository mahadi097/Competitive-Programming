class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i, n = 0, len(bits)
        while i < n:
            if bits[i] == 1:
                i += 1
            elif i == n-1:
                return True
            i += 1
        return False