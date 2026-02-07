class Solution:
    def doesAliceWin(self, s: str) -> bool:
        for c in s:
            if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
                return True
        return False