class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        last1 = -k-1
        for i in range(len(nums)):
            if nums[i] == 1:
                if i-last1 <= k:
                    return False
                last1 = i
        
        return True