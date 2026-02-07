class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            total_sum = f = 0
            x = 1
            while x*x <= num:
                if num%x == 0:
                    f += 1
                    total_sum += x
                    y = num // x
                    if x != y:
                        f += 1
                        total_sum += y
                x += 1
            if f == 4:
                ans += total_sum
        
        return ans