class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        n = len(prices)
        cum = [0 for _ in range(n)]
        cum1 = [0 for _ in range(n)]
        for i in range(n):
            cum[i] = cum[i-1] + (strategy[i] * prices[i])
            cum1[i] = cum1[i-1] + prices[i]
        
        ans = cum[n-1]
        kk = k // 2
        for i in range(n):
            if i+k > n:
                break
            total = cum[n-1]
            total -= (cum[i+k-1] - (0 if i-1 < 0 else cum[i-1]))
            total += (cum1[i+k-1] - cum1[i+kk-1])
            ans = max(ans, total)
        
        return ans