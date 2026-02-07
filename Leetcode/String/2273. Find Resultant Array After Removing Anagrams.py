class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        final_words = []

        i = 0
        while i < len(words):
            final_words.append(words[i])
            j = i+1
            while j < len(words) and sorted(words[i]) == sorted(words[j]):
                j += 1
            i = j
        
        return final_words