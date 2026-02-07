class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        mn = inf
        for i in range(1, len(arr)):
            mn = min(mn, arr[i]-arr[i-1])
        pairs = []
        for i in range(1, len(arr)):
            if arr[i]-arr[i-1] == mn:
                pairs.append([arr[i-1], arr[i]])
        return pairs