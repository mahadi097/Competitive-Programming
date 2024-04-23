class Solution {
public:

    int lengthOfLongestSubstring(string s) {
    	int n = s.size();

    	if(!n) return 0;

        map <char, int> f;
        int st = 0, en = 0, ans = 1;
        f[s[0]] = 1;

        while(en < n) {
            int good = 1;
            for(auto p: f) {
                if(p.second > 1) { good = 0; break; }
            }

            if(good) {
                ans = max(ans, en-st+1);
                en++;
                if(en < n) f[s[en]]++;
            }
            else {
                f[s[st]]--;
                st++;
                if(st > en) {
                    en++;
                    if(en < n) f[s[en]]++;
                }
            }
        }

        return ans;
    }
};


