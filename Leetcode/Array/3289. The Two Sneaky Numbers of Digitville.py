class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        ans = []
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                ans.append(nums[i])
        return ans