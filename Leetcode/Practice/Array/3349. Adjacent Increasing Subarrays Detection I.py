class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        i = 0
        while i+(2*k-1) < len(nums):
            strict_a = True
            for j in range(i+1, i+k):
                if nums[j] <= nums[j-1]:
                    strict_a = False
                    break
            strict_b = True
            for j in range(i+k+1, i+2*k):
                if nums[j] <= nums[j-1]:
                    strict_b = False
                    break
            if strict_a and strict_b:
                return True
            i += 1
        
        return False