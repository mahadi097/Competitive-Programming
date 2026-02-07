class Solution {
private:
    int intVal(char c) {
        return c - 'a';
    }
public:
    int appendCharacters(string s, string t) {
        queue<int> pos[26];

        for(int i = 0; i < s.size(); i++) pos[intVal(s[i])].push(i);

        int lastIn = -1, ans = 0;
        for(int i = 0; i < t.size(); i++) {
            int inC = intVal(t[i]);
            
            bool found = false;
            while(!found and !pos[inC].empty()) {
                int posC = pos[inC].front();
                pos[inC].pop();
                
                if(posC > lastIn) {
                    lastIn = posC;
                    found = true;
                    break;
                }
            }

            if(!found) {
                ans = t.size() - i;
                break;
            }
        }

        return ans;
    }
};