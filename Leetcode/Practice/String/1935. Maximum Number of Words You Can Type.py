class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        ans = 0
        words = text.split()
        
        for word in words:
            ok = True
            for c in word:
                if c in brokenLetters:
                    ok = False
                    break
            if ok:
                ans += 1
            
        return ans