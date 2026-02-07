class Solution:
    def maxFreqSum(self, s: str) -> int:
        v = c = 0
        f = [0 for _ in range(26)]

        for ch in s:
            f[ord(ch)-ord('a')] += 1

        def vowel(ch: str) -> bool:
            return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'
        
        for ch in range(ord('a'), ord('z')+1):
            if vowel(chr(ch)):
                v = max(v, f[ch-ord('a')])
            else:
                c = max(c, f[ch-ord('a')])
        
        return v+c