class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        same = defaultdict(bool)
        cap = defaultdict(str)
        vowel = defaultdict(str)

        vowels = "aeiou"
        def is_vowel(c: str) -> bool:
            return c in vowels 

        def sanitize_vowel(word: str) -> str:
            new_word = ""
            for c in word:
                if is_vowel(c):
                    new_word += "*"
                else:
                    new_word += c
            
            return new_word

        for word in wordlist:
            same[word] = True
            word_lower = word.lower()
            if not cap[word_lower]: 
                cap[word_lower] = word
            if not vowel[sanitize_vowel(word_lower)]:
                vowel[sanitize_vowel(word_lower)] = word
        
        ans = []
        for q in queries:
            q_lower = q.lower()
            if same[q]:
                ans.append(q)
            elif cap[q_lower]:
                ans.append(cap[q_lower])
            elif vowel[sanitize_vowel(q_lower)]:
                ans.append(vowel[sanitize_vowel(q_lower)])
            else:
                ans.append("")
        
        return ans
