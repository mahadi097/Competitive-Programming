class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)

        if n == 1: return ans

        ones = [0 for _ in range(n)]

        for i in range(n-1, -1, -1):
            if nums[i] == 0:
                ones[i] = 0
            else:
                if i == n-1:
                    ones[i] = 1
                else:
                    ones[i] = 1 + ones[i+1]
        
        c = 0
        for i in range(n):
            t = c
            if i != n-1:
                t += ones[i+1]
            ans = max(ans, t)

            if nums[i] == 0:
                c = 0
            else:
                c += 1
        
        return ans
