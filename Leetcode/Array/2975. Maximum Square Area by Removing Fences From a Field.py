class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        hFences.append(1)
        hFences.append(m)
        vFences.append(1)
        vFences.append(n)
        hFences.sort()
        vFences.sort()
        
        hset = set()
        for i in range(len(hFences)):
            for j in range(i+1, len(hFences)):
                hset.add(hFences[j]-hFences[i])
        
        size = 0
        for i in range(len(vFences)):
            for j in range(i+1, len(vFences)):
                ln = vFences[j]-vFences[i]
                if ln in hset:
                    size = max(size, ln)
        
        return ((size * size) % (10**9 + 7)) if size > 0 else -1