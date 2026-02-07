class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        gcd_all = nums[0]
        for i in range(n):
            gcd_all = math.gcd(gcd_all, nums[i])
        
        if gcd_all > 1:
            return -1
        ones = nums.count(1)
        if ones:
            return n - ones

        ans = inf
        for i in range(n):
            a = list(nums)
            left_op = right_op = 0
            left_op_pos = right_op_pos = False
            for j in range(i, 0, -1):
                a[j-1] = math.gcd(a[j-1], a[j])
                left_op += 1
                if a[j-1] == 1:
                    left_op_pos = True
                    break
            if not left_op_pos:
                left_op = inf
            else:
                left_op += n-1
            for j in range(i, n-1):
                a[j+1] = math.gcd(a[j+1], a[j])
                right_op += 1
                if a[j+1] == 1:
                    right_op_pos = True
                    break
            if not right_op_pos:
                right_op = inf
            else:
                right_op += n-1
            
            ans = min(ans, left_op, right_op)
        
        return ans