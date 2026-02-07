from sortedcontainers import SortedList

class Solution:
  def longestSubarray(self, nums: List[int], limit: int) -> int:
    n = len(nums)
    ans = j = 0
    
    sub_array = SortedList()
    sub_array.add(nums[0])
    
    def isInRange() -> bool:
      return sub_array[-1] - sub_array[0] <= limit
    
    
    for i in range(n):
      if i != 0: sub_array.remove(nums[i-1])
      
      while j < n and isInRange():
        j += 1        
        if j < n: sub_array.add(nums[j])
        
      ans = max(ans, j-i)
    
    return ans
    