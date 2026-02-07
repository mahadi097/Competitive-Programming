class Solution:
    def maximum69Number (self, num: int) -> int:
        n = num
        s = str(num)
        for i in range(len(s)):
            if s[i] == '6':
                s = s[:i] + '9' + s[i+1:]
                n = int(s)
                break
        
        return n