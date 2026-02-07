class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        ans = prv = 0
        for v in target:
            if v > prv:
                ans += (v - prv)
            prv = v
        return ans