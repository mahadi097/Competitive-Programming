class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:

        def possible(dis: int) -> int:
            count = 1
            lastPos = position[0]
            
            for i in range(1, len(position)):
                if position[i]-lastPos >= dis:
                    count += 1
                    lastPos = position[i]
            
            return count >= m
 
            
        position.sort()
        
        st, en = 1, max(position)
        ans = en
        
        while st <= en:
            mid = (st + en) // 2
            if possible(mid):
                ans = mid
                st = mid + 1
            else:
                en = mid - 1
        
        return ans