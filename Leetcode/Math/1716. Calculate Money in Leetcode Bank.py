class Solution:
    def totalMoney(self, n: int) -> int:
        t = prv_m = prv = 0
        for i in range(n):
            if i%7 == 0:
                t += prv_m + 1
                prv_m += 1
                prv = prv_m
            else:
                t += prv + 1
                prv += 1
        
        return t