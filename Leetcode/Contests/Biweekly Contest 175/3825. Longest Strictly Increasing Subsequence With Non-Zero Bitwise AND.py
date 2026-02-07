class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        f = defaultdict(list)
        for num in nums:
            for i in range(32):
                if (num >> i) & 1:
                    f[i].append(num)
        
        def solve(arr):
            dp = []
            for x in arr:
                pos = bisect_left(dp, x)
                if pos == len(dp):
                    dp.append(x)
                else:
                    dp[pos] = x
            return len(dp)

        ans = 0
        for i in range(32):
            if f[i]:
                ans = max(ans, solve(f[i]))
        return ans