class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n = len(rains)
        last = defaultdict(int)
        dry = SortedList()
        ans = [1 for _ in range(n)]

        for index, lake, in enumerate(rains, start=1):
            if lake == 0:
                dry.add(index)
            else:
                ans[index-1] = -1
                if not last[lake]:
                    last[lake] = index
                else:
                    pos = dry.bisect_left(last[lake])
                    if pos == len(dry):
                        return []
                    ans[dry[pos]-1] = lake
                    dry.discard(dry[pos])
                    last[lake] = index
        
        return ans