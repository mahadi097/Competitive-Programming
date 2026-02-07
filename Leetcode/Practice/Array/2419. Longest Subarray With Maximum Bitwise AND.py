class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        mx = max(nums)
        ans = c = 0
        
        for num in nums:
            if num == mx:
                c += 1
            else:
                c = 0
            ans = max(ans, c)
        
        return ans