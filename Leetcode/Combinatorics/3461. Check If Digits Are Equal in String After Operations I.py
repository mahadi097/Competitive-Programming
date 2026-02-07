class Solution:
    def hasSameDigits(self, s: str) -> bool:
        p = [1]
        while len(p) < len(s)-1:
            newP = [1]
            for i in range(1, len(p)):
                newP.append(p[i-1] + p[i])
            newP.append(1)
            p = newP
        
        d1 = d2 = 0
        for i in range(len(p)):
            d1 = (d1 + p[i] * int(s[i])) % 10
            d2 = (d2 + p[i] * int(s[i+1])) % 10
            print(p[i], s[i])

        return d1 == d2