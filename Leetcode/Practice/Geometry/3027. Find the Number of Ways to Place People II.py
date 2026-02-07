class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        ans = 0
        n = len(points)
        points.sort(key=lambda x: (x[0], -x[1]))

        def valid_AB(A, B) -> bool:
            return A[0] <= B[0] and A[1] >= B[1]

        for i, A in enumerate(points):
            max_y = -inf
            for j in range(i+1, n):
                B = points[j]
                if valid_AB(A, B):
                    if max_y < B[1]:
                        ans += 1

                if B[1] <= A[1]:
                    max_y = max(max_y, B[1])
                
        return ans