class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        dp = [[[-1 for _ in range(2)] for _ in range(m)] for _ in range(n)]

        def solve(p1: int, p2: int, taken: int) -> int:
            if p1 == n or p2 == m:
                return 0 if taken == 1 else -inf
            if dp[p1][p2][taken] != -1:
                return dp[p1][p2][taken]
            
            r1 = nums1[p1] * nums2[p2] + solve(p1+1, p2+1, 1)
            r2 = solve(p1+1, p2, taken)
            r3 = solve(p1, p2+1, taken)
            dp[p1][p2][taken] = max(r1, r2, r3)
            return dp[p1][p2][taken]
        
        return solve(0, 0, 0)