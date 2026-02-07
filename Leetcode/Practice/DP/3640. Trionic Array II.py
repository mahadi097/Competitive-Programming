class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[[-1 for _ in range(2)] for _ in range(3)] for _ in range(n)]

        def solve(i: int, p: int, ln: int) -> int:
            if i == n:
                if p == 2 and ln == 1:
                    return 0
                else:
                    return -inf
            if dp[i][p][ln] != -1:
                return dp[i][p][ln]
            
            res = -inf
            if p == 0:
                if nums[i] > nums[i-1]:
                    r1 = nums[i] + solve(i+1, 0, 1)
                    r2 = nums[i] + solve(i+1, 1, 0)
                    res = max(r1, r2)
            elif p == 1:
                if nums[i] < nums[i-1]:
                    r1 = nums[i] + solve(i+1, 1, 1)
                    r2 = nums[i] + solve(i+1, 2, 0)
                    res = max(r1, r2)
            else:
                if nums[i] > nums[i-1]:
                    r1 = nums[i] + solve(i+1, 2, 1)
                    r2 = nums[i]
                    res = max(r1, r2)

            dp[i][p][ln] = res
            return dp[i][p][ln]

        ans = -inf
        for i in range(n):
            ans = max(ans, nums[i] + solve(i+1, 0, 0))
        
        return ans