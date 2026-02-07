class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        adj = [[] for _ in range(26)]
        dis = [[inf for _ in range(26)] for _ in range(26)]

        def val(ch: str) -> int:
            return ord(ch) - ord('a')

        for c1, c2, c in zip(original, changed, cost):
            adj[val(c1)].append((val(c2), c))
        
        def dijkstra(src: int) -> None:
            dis[src][src] = 0
            pq = [(0, src)]

            while pq:
                d, u = heapq.heappop(pq)

                for v, w in adj[u]:
                    if d+w < dis[src][v]:
                        dis[src][v] = d + w
                        heapq.heappush(pq, (d+w, v))
        
        for i in range(26):
            dijkstra(i)
        
        ans = 0
        for c1, c2 in zip(source, target):
            d = dis[val(c1)][val(c2)]
            if d == inf:
                return -1
            ans += d
        
        return ans