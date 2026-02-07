class Solution {
private:
    //Trie
    struct Trie {
        Trie *Next[26];
        bool endMark;

        Trie() {
            endMark = false;
            for(int i = 0; i < 26; i++) Next[i] = NULL;
        }
    } *root;

    void init() {
        root = new Trie();
    }

    void insert(string s) {
        Trie *now = root;
        
        for(int i = 0; i < s.size(); i++) {
            int v = s[i] - 'a';

            if(now->Next[v] == NULL) now->Next[v] = new Trie();
            now = now->Next[v];
        }
        
        now->endMark = true;
    }

    string search(string s) {
        Trie *now = root;
        string rootS;

        for(int i = 0; i < s.size(); i++) {
            int v = s[i] - 'a';
            rootS.push_back(s[i]);
            
            if(now->Next[v] == NULL) return s;
            
            now = now->Next[v];
            if(now->endMark) return rootS;
        }

        return s;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        init();

        for(auto word: dictionary) {
            insert(word);
        }

        string ans;
        int n = sentence.size();
        for(int  i = 0; i < n; i++) {
            string word;
            while(i < n and sentence[i] != ' ') {
                word.push_back(sentence[i]);
                i++;
            }

            string rootWord = search(word);
            ans += rootWord;
            if(i < n) ans.push_back(' ');
        }

        return ans;
    }
};