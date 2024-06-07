class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> f(26, 101);

        for(auto word: words) {
            vector<int> fW(26, 0);
            for(auto c: word) fW[c-'a']++;
            for(int i = 0; i < 26; i++) f[i] = min(f[i], fW[i]);
        }

        for(int i = 0; i < 26; i++) {
            while(f[i] > 0) {
                string s = string(1, 'a' + i);
                ans.push_back(s);
                f[i]--;
            }
        }

        return ans;
    }
};