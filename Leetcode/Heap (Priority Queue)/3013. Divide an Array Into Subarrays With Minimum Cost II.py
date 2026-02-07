class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        ans, s = inf, nums[0]
        a = SortedList()
        n, j = len(nums), 2
        k -= 2
        for i in range(1, n):
            if i+k == n:
                break
            s += nums[i]
            if i != 1:
                s -= nums[i-1]
                pos = a.bisect_left(nums[i])
                if pos < k:
                    s -= nums[i]
                    if len(a) > k:
                        s += a[k]
                a.discard(nums[i])

            while j < n and j-i <= dist:
                pos = a.bisect_left(nums[j])
                a.add(nums[j])
                if pos < k:
                    s += nums[j]
                    if len(a) > k:
                        s -= a[k]
                j += 1
            ans = min(ans, s)
        
        return ans