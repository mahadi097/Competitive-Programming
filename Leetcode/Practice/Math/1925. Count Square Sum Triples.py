class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        for c in range(1, n+1):
            for b in range(1, c):
                a = int(math.sqrt(c*c - b*b))
                if a*a == (c*c - b*b):
                    ans += 1
        
        return ans