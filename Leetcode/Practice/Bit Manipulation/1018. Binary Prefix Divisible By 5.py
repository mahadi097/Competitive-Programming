class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        cur = 0
        ans = []
        for num in nums:
            cur = (cur * 2 + num) % 5
            ans.append(True if cur == 0 else False)
        
        return ans