class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = []
        for i, val in enumerate(nums):
            if val > 0:
                j = i + val%n
                if j >= n:
                    j -= n
                res.append(nums[j])
            elif val < 0:
                j = i - abs(val)%n
                if j < 0:
                    j = n+j
                res.append(nums[j])
            else:
                res.append(val)
        
        return res