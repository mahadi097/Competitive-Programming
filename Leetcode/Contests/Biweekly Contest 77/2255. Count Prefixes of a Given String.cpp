class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;

        for(int i = 0; i < words.size(); i++) {
            string w = words[i];
            int j, k;
            for(j = 0, k = 0; j < w.size(); j++, k++) {
                if(w[j] != s[k]) break;
            }

            if(j == w.size()) ans++;
        }

        return ans;
    }
};