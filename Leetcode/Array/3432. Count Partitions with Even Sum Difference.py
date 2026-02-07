class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        total = sum(nums)
        ans = totalL = 0
        for i in range(len(nums)-1):
            totalL += nums[i]
            totalR = total - totalL
            if (totalL - totalR) & 1 == 0:
                ans += 1
        
        return ans