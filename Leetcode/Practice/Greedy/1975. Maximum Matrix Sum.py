class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        mn, total_minus, total_sum = inf, 0, 0
        has_zero = False
        for row in matrix:
            for el in row:
                mn = min(mn, abs(el))
                if el < 0:
                    total_minus += 1
                    total_sum -= el
                else:
                    total_sum += el
                    if el == 0:
                        has_zero = True
        
        if total_minus & 1 == 0 or has_zero:
            return total_sum
        total_sum -= (2 * mn)
        return total_sum