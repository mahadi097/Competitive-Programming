class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        ans = -inf
        n = len(nums)
        dp = [-inf for _ in range(n)]
        cum = [0 for _ in range(n)]

        for i in range(n):
            cum[i] = cum[i-1] + nums[i]
            if i-k+1 >= 0:
                mx1 = cum[i] if i-k+1 == 0 else cum[i]-cum[i-k]
                mx2 = -inf if i-k < 0 else dp[i-k] + mx1
                dp[i] = max(mx1, mx2)
                ans = max(ans, dp[i])
        
        return ans