class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        n = len(prices)
        i = ans = 0
        while i < n:
            j = i+1
            while j < n and prices[j-1]-prices[j] == 1:
                j += 1
            ans += ((j-i) * (j-i+1)) // 2
            i = j
        return ans