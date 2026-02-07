class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        vals = [[] for _ in range(3)]
        ans = 0
        
        for num in nums:
            ans += num
            if num%3 == 0:
                continue
            vals[num%3].append(num)
        vals[1].sort()
        vals[2].sort()
        
        if ans%3 == 1:
            subtract1 = inf if len(vals[1]) == 0 else vals[1][0]
            subtract2 = inf if len(vals[2]) < 2 else (vals[2][0] + vals[2][1])
            ans = max(ans-subtract1, ans-subtract2)
        elif ans%3 == 2:
            subtract1 = inf if len(vals[2]) == 0 else vals[2][0]
            subtract2 = inf if len(vals[1]) < 2 else (vals[1][0] + vals[1][1])
            ans = max(ans-subtract1, ans-subtract2)

        return ans