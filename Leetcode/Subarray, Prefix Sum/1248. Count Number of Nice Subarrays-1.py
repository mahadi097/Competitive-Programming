class Solution:
  def numberOfSubarrays(self, nums: List[int], k: int) -> int:
    n = len(nums)
    odds = 1
    ans = st = en = 0
    
    for i in range(n):
      if i != 0 and nums[i-1]%2 == 0: ans += (en - st)
      else: 
        odds -= 1
        st = en
        while st < n: 
          if nums[st]%2 == 1: 
            odds += 1
            if odds == k: break            
          st += 1
        
        if st == n: break
                
        en = st + 1
        while en < n and nums[en]%2 == 0: en += 1
        
        ans += (en - st)
    
    return ans