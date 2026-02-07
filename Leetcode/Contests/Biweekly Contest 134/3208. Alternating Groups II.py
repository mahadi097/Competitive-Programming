class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        ans = 0
        n = len(colors)

        total, prv_val = 0, -1
        for i in range(-k+1, n, 1):
            if colors[i] == prv_val:
                total = 1
            else:
                total += 1
                if total == k:
                    ans += 1
                    total -= 1
            prv_val = colors[i]

        return ans
    