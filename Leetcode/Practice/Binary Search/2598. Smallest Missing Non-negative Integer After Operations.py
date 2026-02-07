class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        exist = defaultdict(bool)

        for num in nums:
            nn = num % value # lowest non-negative
            new_num = nn
            st, en = 0, 10 ** 5
            while st <= en:
                mid = (st + en) // 2
                v = nn + (mid * value)
                if not exist[v]:
                    new_num = v
                    en = mid - 1
                else:
                    st = mid + 1
            exist[new_num] = True
        
        for v in range(0, 10**5+1):
            if not exist[v]:
                return v