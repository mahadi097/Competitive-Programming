class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(customers)
        cumAll = [0] * n
        cumG = [0] * n
        
        for i in range(n):
          cumAll[i] = cumAll[i-1] + customers[i]
          cumG[i] = cumG[i-1] + (0 if grumpy[i] == 1 else customers[i])
          
        ans = i = 0
        while i+minutes-1 < n:
          current = cumAll[i+minutes-1] + (cumG[n-1]  - cumG[i+minutes-1])
          if i != 0:
            current = current - cumAll[i-1] + cumG[i-1]
          
          ans = max(ans, current)
          i += 1
            
        return ans
          
        