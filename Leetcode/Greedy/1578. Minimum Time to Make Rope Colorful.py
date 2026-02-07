class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        ans, n = 0, len(colors)
        i = 0
        while i < n:
            j, mx, t = i+1, neededTime[i], neededTime[i]
            while j < n and colors[j] == colors[i]:
                mx = max(mx, neededTime[j])
                t += neededTime[j]
                j += 1
            if j-i > 1:
                ans += (t - mx)
            i = j
        
        return ans