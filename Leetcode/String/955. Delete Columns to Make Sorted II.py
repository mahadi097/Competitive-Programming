class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n, m = len(strs), len(strs[0])
        ans = 0
        already_small = defaultdict(bool)

        def is_lexicographic(i: int) -> bool:
            for j in range(n-1):
                if strs[j][i] > strs[j+1][i] and not already_small[j]:
                    return False
            for j in range(n-1):
                if strs[j][i] < strs[j+1][i]:
                    already_small[j] = True
            return True

        for i in range(m):
            if not is_lexicographic(i):
                ans += 1

        return ans