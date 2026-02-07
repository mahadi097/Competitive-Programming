class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        f = defaultdict(int)
        for num in nums:
            f[num] += 1
            if f[num] > 1:
                return num