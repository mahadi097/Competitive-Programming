class Solution {
public:
    bool dp[2005][2005], f[2005];
    char S[2005], P[2005];

    bool isMatch(string s, string p) {
        int lnS = s.size(), lnP = p.size();

        for(int i = 0; i < lnS; i++) S[i+1] = s[i];
        for(int i = 0; i < lnP; i++) P[i+1] = p[i];

        for(int i = 1; i <= lnP; i++) {
            if(P[i] != '*') break;
            dp[i][0] = 1;
        }

        dp[0][0] = 1;
        for(int j = 0; j <= lnS; j++) f[j] = 1;

        for(int i = 1; i <= lnP; i++) {

            for(int j = 1; j <= lnS; j++) {
                if(S[j] == P[i] or P[i] == '?' or P[i] == '*') dp[i][j] = dp[i-1][j-1];
                if(P[i] == '*') {
                    if(f[j]) dp[i][j] = 1;
                }
            }

            for(int j = 1; j <= lnS; j++) {
                if(dp[i][j] == 1) {
                    for(int k = j; k <= lnS; k++) f[k] = 1;
                    break;
                }
                f[j] = 0;
            }
        }

        return dp[lnP][lnS];
    }
};
