class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        d2 = 0
        area = 0
        
        for dim in dimensions:
            curr_d2 = (dim[0] ** 2) + (dim[1] ** 2)
            curr_area = dim[0] * dim[1]

            if curr_d2 > d2:
                d2 = curr_d2
                area = curr_area
            elif curr_d2 == d2:
                area = max(area, curr_area)
        
        return area