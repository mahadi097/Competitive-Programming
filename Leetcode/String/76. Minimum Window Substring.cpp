class Solution {
public:
    int f[55], nowF[55];

    int cToV(char c) {
        if(c >= 'a' and c <= 'z') return c - 'a';
        return (c - 'A' + 26);
    }

    string minWindow(string s, string t) {
        string ans;
        int r1 = 0, r2 = 1e9;

        for(auto c: t) f[cToV(c)]++;

        int n = s.size(), st = 0, en = 0;
        nowF[cToV(s[0])]++;

        while(st < n and en < n) {
            bool ok = 1;
            for(int i = 0; i < 52; i++) if(nowF[i] < f[i]) ok = 0;

            if(ok) {
                if(en-st < r2-r1) r1 = st, r2 = en;

                nowF[cToV(s[st])]--;
                st++;
                if(st > en) {
                    en++;
                    if(st < en) nowF[cToV(s[st])]++;
                }
            }
            else {
                en++;
                if(en < n) nowF[cToV(s[en])]++;
            }
        }

        if(r2 == 1e9) return ans;

        for(int i = r1; i <= r2; i++) ans.push_back(s[i]);

        return ans;
    }
};
