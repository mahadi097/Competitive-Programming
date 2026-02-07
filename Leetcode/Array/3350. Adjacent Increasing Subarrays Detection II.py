class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        strict_ln = []
        i = 0
        while i < len(nums):
            j = i+1
            while j < len(nums) and nums[j] > nums[j-1]:
                j += 1
            strict_ln.append(j-i)
            i = j
        
        ans = strict_ln[0] // 2
        for i in range(1, len(strict_ln)):
            ans = max(ans, strict_ln[i] // 2, min(strict_ln[i-1], strict_ln[i]))
        
        return ans