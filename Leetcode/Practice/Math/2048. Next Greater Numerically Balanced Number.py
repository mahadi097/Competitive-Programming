class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        mx_val = 1224444

        def balanced(x: int) -> bool:
            f = Counter(str(x))
            for d in f:
                if int(d) != f[d]:
                    return False
            return True
        
        for x in range(n+1, mx_val+1):
            if balanced(x):
                return x