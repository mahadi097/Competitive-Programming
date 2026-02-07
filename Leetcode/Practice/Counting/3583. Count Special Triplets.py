class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        f = Counter(nums)
        f_cur = defaultdict(int)
        ans = 0
        for num in nums:
            c_left = f_cur[num*2]
            c_right = f[num*2] - f_cur[num*2] - (1 if num == 0 else 0)
            ans = (ans + (c_left * c_right)) % mod
            f_cur[num] += 1
        
        return ans