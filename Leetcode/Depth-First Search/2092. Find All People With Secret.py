class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        know = defaultdict(bool)
        vis = defaultdict(bool)
        adj = defaultdict(list)

        know[0] = know[firstPerson] = True
        meetings.sort(key=lambda x: x[2])

        def dfs(u: int) -> None:
            if vis[u]:
                return
            vis[u] = True
            know[u] = True

            for v in adj[u]:
                dfs(v)

        i, m = 0, len(meetings)
        while i < m:
            people = set()
            cur_time = meetings[i][2]
            while i < m and meetings[i][2] == cur_time:
                p1, p2 = meetings[i][0], meetings[i][1]
                people.add(p1)
                people.add(p2)
                adj[p1].append(p2)
                adj[p2].append(p1)
                i += 1
            for p in people:
                if know[p] and not vis[p]:
                    dfs(p)
            vis.clear()
            adj.clear()
        
        people = []
        for p in range(n):
            if know[p]:
                people.append(p)
        
        return people