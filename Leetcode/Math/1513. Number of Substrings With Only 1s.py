class Solution:
    def numSub(self, s: str) -> int:
        ans = i = 0
        n = len(s)
        mod = 10 ** 9 + 7
        while i < n:
            if s[i] == '1':
                c = 0
                while i < n and s[i] == '1':
                    c += 1
                    i += 1
                t = (c * (c+1)) // 2
                ans = (ans + t) % mod
            else:
                i += 1
        
        return ans