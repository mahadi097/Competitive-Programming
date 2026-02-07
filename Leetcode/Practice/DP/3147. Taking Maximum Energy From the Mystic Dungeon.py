class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        n = len(energy)
        dp = [0] * n
        ans = -inf
        for i, e in enumerate(energy):
            dp[i] = e if i-k < 0 else max(e, dp[i-k]+e)
            if i+k >= n:
                ans = max(ans, dp[i])
        
        return ans