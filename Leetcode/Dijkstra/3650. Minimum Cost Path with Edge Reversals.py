class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        adj = defaultdict(list)
        adj_in = defaultdict(list)
        for u, v, w in edges:
            adj[u].append((v, w))
            adj_in[v].append((u, w))

        dis = [inf for _ in range(n)]
        dis[0] = 0
        pq = []
        heapq.heappush(pq, (dis[0], 0))

        while pq:
            d, u = heapq.heappop(pq)

            for v, w in adj[u]:
                if d+w < dis[v]:
                    dis[v] = d + w
                    heapq.heappush(pq, (dis[v], v))
            for v, w in adj_in[u]:
                if d+2*w < dis[v]:
                    dis[v] = d + 2*w
                    heapq.heappush(pq, (dis[v], v))
        
        return -1 if dis[n-1] == inf else dis[n-1]