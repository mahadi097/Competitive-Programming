class Solution:
    def bestClosingTime(self, customers: str) -> int:
        earliest_hour, min_penalty = 0, inf
        cy = customers.count('Y')
        cn = 0
        for i in range(len(customers)):
            if cy + cn < min_penalty:
                min_penalty = cy + cn
                earliest_hour = i
            if customers[i] == 'Y':
                cy -= 1
            else:
                cn += 1
        if cy + cn < min_penalty:
            earliest_hour = len(customers)
        
        return earliest_hour