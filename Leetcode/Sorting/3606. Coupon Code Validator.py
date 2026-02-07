class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        catagories = { "electronics": 0, "grocery": 1, "pharmacy": 2, "restaurant": 3 }
        valid_coupons = []
        n = len(code)
        
        def is_valid(i: int) -> bool:
            if len(code[i]) == 0:
                return False
            if businessLine[i] not in catagories:
                return False
            if not isActive[i]:
                return False
            for ch in code[i]:
                if not ch.isalnum() and ch != "_":
                    return False
            return True 
        
        for i in range(n):
            if is_valid(i):
                valid_coupons.append([code[i], catagories[businessLine[i]]])
        
        valid_coupons.sort(key=lambda x: (x[1], x[0]))
        valid_coupons = [code for code, _ in valid_coupons]

        return valid_coupons