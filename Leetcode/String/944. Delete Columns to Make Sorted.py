class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        m, n = len(strs), len(strs[0])
        ans = 0
        for i in range(n):
            col = []
            for j in range(m):
                col.append(strs[j][i])
            if sorted(col) != col:
                ans += 1
        
        return ans