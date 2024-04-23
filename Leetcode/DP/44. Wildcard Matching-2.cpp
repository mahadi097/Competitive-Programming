class Solution {
public:
    bool dp[2005][2005], f[2005], ok[2005];

    bool isMatch(string s, string p) {
        int lnS = s.size(), lnP = p.size();

        if(lnS == 0) {
            for(int i = 0; i < lnP; i++) if(p[i] != '*') return 0;
            return 1;
        }
        if(lnP == 0) return 0;

        for(int i = 0; i < lnP; i++) {
            if(p[i] != '*') break;
            ok[i] = 1;
        }
        for(int j = 0; j < lnS; j++) f[j] = 1;

        for(int i = 0; i < lnP; i++) {
            bool st = 0;
            for(int j = 0; j < lnS; j++) {
                if(s[j] == p[i] or p[i] == '?' or p[i] == '*') {
                    if(i == 0) {
                        if(j == 0 or p[i] == '*') dp[i][j] = 1;
                    }
                    else if(j == 0) {
                        if((s[j] == p[i] or p[i] == '?') and ok[i-1]) dp[i][j] = 1;
                    }
                    else dp[i][j] = dp[i-1][j-1];
                }
                if(p[i] == '*') {
                    if(f[j]) dp[i][j] = 1;
                }

                if(dp[i][j]) st = 1;

                f[j] = st;
            }
        }

        return dp[lnP-1][lnS-1];
    }
};
