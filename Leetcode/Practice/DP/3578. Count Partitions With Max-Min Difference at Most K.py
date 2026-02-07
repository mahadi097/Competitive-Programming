class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        mod = 10**9 + 7
        n = len(nums)
        st = [i for i in range(n)]
        dp = [0] * n
        cum = [0] * n
        
        i, j = n-1, n-2
        vals = SortedList()
        vals.add(nums[n-1])
        vals.add(nums[n-2])
        while i >= 0:
            while j >= 0:
                if vals[-1]-vals[0] > k:
                    break
                j -= 1
                if j >= 0:
                    vals.add(nums[j])
            st[i] = j+1
            vals.discard(nums[i])
            i -= 1
        
        dp[0] = 1
        cum[0] = 2
        for i in range(1, n):
            if st[i]-2 == -2:
                dp[i] = cum[i-1]
            elif st[i]-2 == -1:
                dp[i] = (cum[i-1] - 1) % mod
            else:
                dp[i] = (cum[i-1] - cum[st[i]-2]) % mod
            cum[i] = (cum[i-1] + dp[i]) % mod
        
        return dp[n-1]