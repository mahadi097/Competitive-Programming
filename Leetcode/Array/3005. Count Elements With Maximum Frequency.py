class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        mx_f = 0
        f = defaultdict(int)
        for num in nums:
            f[num] += 1
            mx_f = max(mx_f, f[num])
        
        ans = 0
        for key in f:
            if f[key] == mx_f:
                ans += mx_f

        return ans