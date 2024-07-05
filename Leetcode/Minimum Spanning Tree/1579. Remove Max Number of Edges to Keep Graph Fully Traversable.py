class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        edges.sort(key=lambda x: x[0], reverse=True)
        for edge in edges:
            edge[1] -= 1
            edge[2] -= 1

        par = [i for i in range(n)]

        def init_parent() -> None:
            for i in range(n):
                par[i] = i

        def find_par(x: int):
            if par[x] == x:
                return x
            par[x] = find_par(par[x])
            return par[x]

        def union_nodes(x: int, y: int) -> bool:
            u = find_par(x)
            v = find_par(y)

            if u != v:
                par[v] = u
                return True
            return False

        edges_removed_type3 = 0

        def cal_edges_for_each(edge_type: int, is_cal_type3_edges_remove: bool = False) -> int:
            nonlocal edges_removed_type3
            total_edges_removed = total_edges_connected = 0
            for edge in edges:
                if edge[0] == edge_type or edge[0] == 3:
                    union_succeeded = union_nodes(edge[1], edge[2])
                    if union_succeeded:
                        total_edges_connected += 1
                    else:
                        total_edges_removed += 1
                        if edge[0] == 3 and is_cal_type3_edges_remove:
                            edges_removed_type3 += 1
            return total_edges_removed if total_edges_connected == n-1 else -1

        edges_removed_alice = cal_edges_for_each(1, True)
        init_parent()
        edges_removed_bob = cal_edges_for_each(2)

        if edges_removed_alice == -1 or edges_removed_bob == -1:
            return -1
        edges_removed_max = edges_removed_alice + edges_removed_bob - edges_removed_type3
        return edges_removed_max
      