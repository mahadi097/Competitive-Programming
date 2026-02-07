class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        i = 1
        while i < n:
            if nums[i] <= nums[i-1]:
                break
            i += 1
        if i == 1:
            return False
        j = i
        while j < n:
            if nums[j] >= nums[j-1]:
                break
            j += 1
        if j == i:
            return False
        k = j
        while k < n:
            if nums[k] <= nums[k-1]:
                break
            k += 1
        if k < n or k == j:
            return False
        return True