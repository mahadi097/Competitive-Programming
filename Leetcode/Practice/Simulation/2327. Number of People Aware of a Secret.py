class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        mod = 10 ** 9 + 7
        p = [0 for _ in range(n)]

        for i in range(n):
            if i == 0:
                p[i] = 1
                continue
            if i-forget >= 0:
                p[i-forget] = 0

            for j in range(max(i-forget+1, 0), i-delay+1):
                p[i] = (p[i] + p[j]) % mod
        
        ans = 0
        for i in range(n):
            ans = (ans + p[i]) % mod

        return ans
        