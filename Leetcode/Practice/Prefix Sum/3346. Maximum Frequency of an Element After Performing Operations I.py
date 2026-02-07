class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        f = Counter(nums)
        cum = defaultdict(int)
        mx_val = max(nums)
        
        for i in range(1, mx_val+1):
            cum[i] = cum[i-1] + f[i]
        
        mx = 0
        for x in range(1, mx_val+1):
            l, r = max(1, x-k), min(mx_val, x+k)
            t = cum[r] - cum[l-1] - f[x]
            c = f[x] + min(numOperations, t)
            mx = max(mx, c)
        
        return mx