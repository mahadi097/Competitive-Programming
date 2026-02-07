class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while(s.size() < k) {
            string newS = "";
            for (int i = 0; i < s.size() && s.size()+newS.size() < k; i++) {
                newS.push_back(s[i] != 'z' ? s[i] + 1 : 'a');
            }
            s += newS;
        }

        return s[k-1];
    }
};