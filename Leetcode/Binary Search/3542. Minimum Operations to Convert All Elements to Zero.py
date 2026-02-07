class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        in0 = SortedList()
        ins = defaultdict(list)
        vv = set()
        for i in range(n):
            if nums[i] == 0:
                in0.add(i)
            else:
                ins[nums[i]].append(i)
                vv.add(nums[i])
        vv = sorted(vv)

        ans = 0
        for v in vv:
            op = 1
            for i in range(1, len(ins[v])):
                pos = in0.bisect_right(ins[v][i-1])
                if pos < len(in0) and in0[pos] < ins[v][i]:
                    op += 1
            ans += op
            for inss in ins[v]:
                in0.add(inss)
        
        return ans