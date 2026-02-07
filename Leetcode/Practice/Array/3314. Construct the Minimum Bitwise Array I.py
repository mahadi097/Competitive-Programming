class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            if num == 2:
                ans.append(-1)
                continue
            for v in range(1, num):
                if v | (v+1) == num:
                    break
            ans.append(v)
        
        return ans