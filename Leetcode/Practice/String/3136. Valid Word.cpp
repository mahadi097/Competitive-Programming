class Solution {
public:
    bool isValid(string word) {
        bool hasVowel = false, hasConsonant = false;

        map <char, bool> vowel;
        vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = vowel['A'] = vowel['E'] = vowel['I'] = vowel['O'] = vowel['U'] = true;

        for(char c: word) {
            if((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z')) {
                if(vowel[c]) hasVowel = true;
                else hasConsonant = true; 
            }
            else if(c < '0' or c > '9') return false;
        }

        return word.size() >= 3 and hasVowel and hasConsonant;
    }
};