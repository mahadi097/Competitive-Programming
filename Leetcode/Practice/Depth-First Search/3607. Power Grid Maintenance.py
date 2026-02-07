class Solution:
    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        adj = defaultdict(list)
        for u, v in connections:
            adj[u].append(v)
            adj[v].append(u)
        
        operational = defaultdict(lambda: True)
        visited = defaultdict(bool)
        grid = 0
        grids = defaultdict(SortedList)
        s2g = defaultdict(int) # indicates which station is located at which grid

        def dfs(u: int) -> None:
            if visited[u]:
                return
            visited[u] = True
            grids[grid].add(u)
            s2g[u] = grid
            for v in adj[u]:
                if not visited[v]:
                    dfs(v)
        
        for i in range(1, c+1):
            if not visited[i]:
                grid += 1
                dfs(i)

        ans = []
        for q, s in queries:
            if q == 1:
                if operational[s]:
                    ans.append(s)
                else:
                    if len(grids[s2g[s]]) > 0:
                        ans.append(grids[s2g[s]][0])
                    else:
                        ans.append(-1)
            else:
                operational[s] = False
                grids[s2g[s]].discard(s)
        
        return ans