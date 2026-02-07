class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        n = len(classes)
        rd = SortedList()
        
        for index, c in enumerate(classes):
            r_curr = c[0] / c[1]
            r_new = (c[0] + 1) / (c[1] + 1)
            rd.add([r_new-r_curr, index])
        
        while extraStudents > 0:
            _, index = rd.pop()
            classes[index][0] += 1
            classes[index][1] += 1
            r_curr = classes[index][0] / classes[index][1]
            r_new = (classes[index][0] + 1) / (classes[index][1] + 1)
            rd.add([r_new-r_curr, index])

            extraStudents -= 1
        
        sum = 0
        for c in classes:
            r = c[0] / c[1]
            sum += r

        return sum / n