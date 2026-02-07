class Solution:
    def minimumK(self, nums: List[int]) -> int:
        ans = 10**5 + 2
        
        def operations(k: int) -> bool:
            cnt = 0
            for num in nums:
                cnt += num // k + (1 if num % k != 0 else 0)
            return cnt <= k**2
        
        st, en = 1, ans
        while st <= en:
            mid = (st + en) // 2
            if operations(mid):
                ans = mid
                en = mid - 1
            else:
                st = mid + 1
        return ans