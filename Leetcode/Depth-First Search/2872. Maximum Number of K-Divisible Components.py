class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adj = defaultdict(list)
        ans = 0
        
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        def dfs(u: int, p: int) -> int:
            nonlocal ans
            sumv = values[u]

            for v in adj[u]:
                if v != p:
                    sumv += dfs(v, u)

            if sumv%k == 0:
                ans += 1
            return sumv%k
        
        dfs(0, 0)
        return ans