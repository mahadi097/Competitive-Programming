class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        ans, n = 0, len(colors)
        for i in range(n):
            if colors[i-1] != colors[i] and colors[i-1] != colors[i-2]:
                ans += 1
        return ans
    