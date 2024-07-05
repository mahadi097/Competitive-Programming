class Solution:
  def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
    out_deg = [0] * n
    done = [False] * n
    adj_list = [[] for _ in range(n)] 

    for edge in edges:
      out_deg[edge[0]] += 1
      adj_list[edge[1]].append(edge[0]) #reverse graph

    ancestors_list = [[] for _ in range(n)]
    included = defaultdict(bool)

    def dfs(u: int) -> None:
      for v in adj_list[u]:
        if not done[v]:
          dfs(v)

        if not included[(u, v)]:
          ancestors_list[u].append(v)
          included[(u, v)] = True

        for ancestor in ancestors_list[v]:
          if not included[(u, ancestor)]:
            ancestors_list[u].append(ancestor)
            included[u, ancestor] = True

      done[u] = True

    for node in range(n):
      if out_deg[node] == 0:
        dfs(node)

    for i in range(n):
      ancestors_list[i].sort()

    return ancestors_list
  