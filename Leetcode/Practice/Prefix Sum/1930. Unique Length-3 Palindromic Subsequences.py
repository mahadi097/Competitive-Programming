class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        def getNum(c: str) -> int:
            return ord(c) - ord('a')

        n = len(s)
        f = [[0 for _ in range(26)] for _ in range(n)]
        palindromes = set()

        for i in range(n):
            num = getNum(s[i])
            for j in range(26):
                f[i][j] = f[i-1][j] + (1 if j == num else 0)
        
        for i in range(1, n-1):
            num = getNum(s[i])
            for j in range(26):
                f1, f2 = f[i-1][j], f[n-1][j] - f[i][j]
                if f1 > 0 and f2 > 0:
                    palindromes.add((j, num))
        
        return len(palindromes)