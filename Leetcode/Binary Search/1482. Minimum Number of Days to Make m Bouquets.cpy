
class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
      if m*k  > len(bloomDay): return -1
      
      st, en = min(bloomDay), max(bloomDay)
      ans = en
      
      while st <= en:
        mid = int ((st + en) / 2)
        
        countB = countF = 0
        for bloom in bloomDay:
          if bloom <= mid:
            countF += 1
            if countF == k:
              countB += 1
              countF = 0
          else:
            countF = 0
              
        if countB >= m:
          ans = min(ans, mid)  
          en = mid - 1
        else:
          st = mid + 1
      
      return ans
      