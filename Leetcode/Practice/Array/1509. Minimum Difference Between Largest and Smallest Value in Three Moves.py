class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 4: return 0

        min_diff = sys.maxsize
        nums.sort()
        
        for i in range(4):
            j = (n-1) - (3-i)
            min_diff = min(min_diff, nums[j]-nums[i])
        
        return min_diff
