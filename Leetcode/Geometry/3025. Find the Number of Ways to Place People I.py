class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        ans = 0

        def is_valid_AB(A, B) -> bool:
            return A[0] <= B[0] and A[1] >= B[1]
        
        def is_it_inside(A, B, C) -> bool:
            return C[0] >= A[0] and C[0] <= B[0] and C[1] >= B[1] and C[1] <= A[1]

        for j, B in enumerate(points):
            for i, A in enumerate(points):
                if i == j or not is_valid_AB(A, B): continue
                
                ok = True
                for k, C in enumerate(points):
                    if k == i or k == j: continue

                    if is_it_inside(A, B, C):
                        ok = False
                        break
                    
                if ok:  ans += 1
                  
        return ans