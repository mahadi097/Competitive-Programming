class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        n = len(nums)
        f = defaultdict(int)
        occ = SortedList()
        ans = []
        cur_sum = 0

        for i in range(k):
            occ.discard([-f[nums[i]], -nums[i]])
            f[nums[i]] += 1
            occ.add([-f[nums[i]], -nums[i]])
        for i in range(min(x, len(occ))):
            cur_sum += ((-occ[i][0]) * (-occ[i][1]))
        ans.append(cur_sum)

        i, j = 0, k
        while j < n:
            index = occ.bisect_left([-f[nums[i]], -nums[i]])
            if index < x:
                cur_sum -= (f[nums[i]] * nums[i])
                if x < len(occ):
                    cur_sum += ((-occ[x][0]) * (-occ[x][1]))
            occ.discard([-f[nums[i]], -nums[i]])
            f[nums[i]] -= 1
            if f[nums[i]] > 0:
                occ.add([-f[nums[i]], -nums[i]])
                index = occ.bisect_left([-f[nums[i]], -nums[i]])
                if index < x:
                    cur_sum += (f[nums[i]] * nums[i])
                    if x < len(occ):
                        cur_sum -= ((-occ[x][0]) * (-occ[x][1]))

            index = occ.bisect_left([-f[nums[j]], -nums[j]])
            if index < x and f[nums[j]] > 0:
                cur_sum += nums[j]
                occ.discard([-f[nums[j]], -nums[j]])
                f[nums[j]] += 1
                occ.add([-f[nums[j]], -nums[j]])
            else:
                occ.discard([-f[nums[j]], -nums[j]])
                f[nums[j]] += 1
                occ.add([-f[nums[j]], -nums[j]])
                index = occ.bisect_left([-f[nums[j]], -nums[j]])
                if index < x:
                    cur_sum += (f[nums[j]] * nums[j])
                    if x < len(occ):
                        cur_sum -= ((-occ[x][0]) * (-occ[x][1]))

            ans.append(cur_sum)
            i += 1
            j += 1
            

        return ans