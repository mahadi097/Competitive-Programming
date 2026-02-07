class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            if num == 2:
                ans.append(-1)
                continue
            st = False
            val = 0
            for i in range(32):
                if num & (1<<i):
                    if st or (num & (1<<(i+1))):
                        val |= (1<<i)
                    else:
                        st = True
            ans.append(val)

        return ans 