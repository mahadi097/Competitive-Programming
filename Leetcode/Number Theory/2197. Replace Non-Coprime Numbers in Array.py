class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        ans = []

        for num in nums:
            val = num
            while True:
                if not ans:
                    ans.append(val)
                    break
                
                if math.gcd(ans[-1], val) == 1:
                    ans.append(val)
                    break

                val = math.lcm(ans[-1], val)
                ans.pop()

        return ans