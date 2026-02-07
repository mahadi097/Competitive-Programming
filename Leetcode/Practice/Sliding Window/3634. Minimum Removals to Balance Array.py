class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        j, n = 0, len(nums)
        ans = n-1
        for i in range(n):
            while j < n and nums[j] <= nums[i]*k:
                j += 1
            c = n - (j-i)
            ans = min(ans, c)
        return ans