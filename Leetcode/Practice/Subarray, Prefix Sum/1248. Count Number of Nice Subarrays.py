import bisect 

class Solution:
  def numberOfSubarrays(self, nums: List[int], k: int) -> int:
    n = len(nums)
    odds = [0] * n  
    
    for i in range(n):
      odds[i] = odds[i-1] + nums[i] % 2
    
    ans = 0
    for i in range(n):
      odds_left = odds[i]
      odds_right = odds_left + k - 1
      if(nums[i]%2 == 0): odds_right += 1
      
      lower_bound = bisect.bisect_left(odds, odds_right)
      upper_bound = bisect.bisect_right(odds, odds_right)
      
      ans += (upper_bound - lower_bound)
    
    return ans