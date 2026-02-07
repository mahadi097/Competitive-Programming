class Solution:
    def reverseByType(self, s: str) -> str:
        letters = []
        others = []
        for ch in s:
            if ch.isalpha():
                letters.append(ch)
            else:
                others.append(ch)
        
        
        for i in range(len(s)):
            if s[i].isalpha():
                s = s[:i] + letters.pop() + s[i+1:]
            else:
                s = s[:i] + others.pop() + s[i+1:]
        return s