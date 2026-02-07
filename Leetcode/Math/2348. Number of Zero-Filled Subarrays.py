class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        i = 0
        ans = 0
        while i < len(nums):
            if nums[i] == 0:
                j = i
                while j < len(nums) and nums[j] == 0:
                    j += 1
                c = j - i
                ans += ((c * (c+1)) // 2)
                i = j
            else: i += 1
        
        return ans