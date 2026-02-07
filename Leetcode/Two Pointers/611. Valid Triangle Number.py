class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        ans, n = 0, len(nums)

        for i in range(n-2):
            k = i+1
            for j in range(i+1, n-1):
                if k < j:
                    k = j
                while k+1 < n and nums[i]+nums[j] > nums[k+1]:
                    k += 1
                ans += (k - j)
        
        return ans