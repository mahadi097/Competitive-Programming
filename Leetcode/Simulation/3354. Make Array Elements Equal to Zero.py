class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        n = len(nums)

        cum = [0 for _ in range(n)]
        for i in range(n):
            cum[i] = nums[i] if i == 0 else nums[i] + cum[i-1]
        
        ans = 0
        for i, v in enumerate(nums):
            if v != 0:
                continue
            
            l = 0 if i == 0 else cum[i-1]
            r = 0 if n == n-1 else cum[n-1] - cum[i]
            
            if l == r:
                ans += 2
            elif l == r+1 or l+1 == r:
                ans += 1
        
        return ans