class Solution:
    def sortVowels(self, s: str) -> str:
        v = []

        vowel = defaultdict(bool)
        vowel["A"] = vowel["E"] = vowel["I"] = vowel["O"] = vowel["U"] = True
        vowel["a"] = vowel["e"] = vowel["i"] = vowel["o"] = vowel["u"] = True

        for c in s:
            if vowel[c]:
                v.append(c)
        v.sort()
    
        j = 0
        new_s = ""
        for i in range(len(s)):
            if vowel[s[i]]:
                new_s += v[j]
                j += 1
            else:
                new_s += s[i]
        
        return new_s

