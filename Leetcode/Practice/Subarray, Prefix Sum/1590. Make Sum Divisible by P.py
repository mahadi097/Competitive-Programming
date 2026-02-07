class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        r = sum(nums) % p
        if r == 0:
            return 0
        last = defaultdict(int)
        last[0] = -1
        ans, r_now = len(nums), 0
        for i, num in enumerate(nums):
            r_now = (r_now + num) % p
            r_need = (r_now - r) % p
            if r_need in last:
                ans = min(ans, i-last[r_need])
            last[r_now] = i
        if ans == len(nums):
            ans = -1

        return ans