class Solution {
private:
    unordered_map<string, bool> dic;
    vector<string> sens;

    void solve(int in, string &sen, string &wordCur, string &s) {
        if(in == s.size()) {
            if(dic[wordCur]) sens.push_back(sen);
            return;
        }

        // 1
        sen.push_back(s[in]);
        wordCur.push_back(s[in]);
        
        solve(in+1, sen, wordCur, s);

        sen.pop_back();
        wordCur.pop_back();

        // 2
        if(dic[wordCur]) {
            sen.push_back(' ');
            sen.push_back(s[in]);

            string wordCurNew(1, s[in]);

            solve(in+1, sen, wordCurNew, s);

            sen.pop_back();
            sen.pop_back();
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto word: wordDict) dic[word] = 1;
        
        string sen = "", wordCur = "";
        solve(0, sen, wordCur, s);
        
        return sens;
    }
};