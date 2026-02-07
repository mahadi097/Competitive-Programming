class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        def is_non_decreasing() -> bool:
            for i in range(len(nums)-1):
                if nums[i] > nums[i+1]:
                    return False
            return True
        ans = 0
        while not is_non_decreasing():
            pos, total = -1, inf
            for i in range(len(nums)-1):
                if nums[i]+nums[i+1] < total:
                    pos, total = i, nums[i]+nums[i+1]
            nums.pop(pos)
            nums.pop(pos)
            nums.insert(pos, total)
            ans += 1
        
        return ans
        