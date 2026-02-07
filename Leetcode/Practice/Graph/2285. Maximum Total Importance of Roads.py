class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        deg = [0] * n
        for i in range(len(roads)):
            deg[roads[i][0]] += 1
            deg[roads[i][1]] += 1

        deg.sort(reverse=True)

        total_importance, val_cur = 0, n
        for connection in deg:
            total_importance += (connection * val_cur)
            val_cur -= 1

        return  total_importance