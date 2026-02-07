class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        exist = set(nums)
        while original in exist:
            original *= 2
        
        return original