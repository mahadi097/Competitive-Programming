class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = inf
        for i in range(k-1, len(nums)):
            ans = min(ans, nums[i]-nums[i-k+1])
        return ans