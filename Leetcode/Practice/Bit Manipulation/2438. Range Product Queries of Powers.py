class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        powers = []
        for i in range(30):
            if (n & (1 << i)):
                powers.append(1 << i)
        
        mod = 10**9 + 7
        ans = []

        for query in queries:
            res = 1
            for i in range(query[0], query[1]+1):
                res = (res * powers[i]) % mod
            ans.append(res)
        
        return ans