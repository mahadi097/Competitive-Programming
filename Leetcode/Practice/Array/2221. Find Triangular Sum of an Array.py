class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n = len(nums)
        
        while n != 1:
            n -= 1
            for i in range(n):
                nums[i] = (nums[i] + nums[i+1]) % 10

        return nums[0]