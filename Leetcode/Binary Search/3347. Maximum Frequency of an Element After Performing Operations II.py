class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        f = Counter(nums)
        mx_val = max(nums)
        vals = set()
        nums.sort()
        
        for num in nums:
            l, r = max(1, num-k), min(mx_val, num+k)
            vals.update([l, num, r])
        
        ans = 0
        for val in vals:
            l = bisect.bisect_right(nums, val-k-1)
            r = bisect.bisect_right(nums, val+k)
            t = r - l - f[val]
            c = f[val] + min(t, numOperations)
            ans = max(ans, c)
        
        return ans