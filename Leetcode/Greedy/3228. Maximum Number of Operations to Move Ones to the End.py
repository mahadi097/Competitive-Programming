class Solution:
    def maxOperations(self, s: str) -> int:
        ans = ones = i = 0
        n = len(s)
        while i < n:
            if s[i] == '1':
                while i < n and s[i] == '1':
                    ones += 1
                    i += 1
            else:
                while i < n and s[i] == '0':
                    i += 1
                ans += ones
        
        return ans