class Solution {
public:
    string S;
    int n, dp[102];
    int numDecodings(string s) {
        S = s;
        n = S.size();

        if(s[0] == '0') return 0;

        memset(dp, -1, sizeof dp);

        return numOfWays(0);
    }

    int numOfWays(int pos) {
        if(pos == n) return 1;
        if(dp[pos] != -1) return dp[pos];

        int t1 = 0, t2 = 0;

        int v1 = S[pos] - '0';
        if(v1 > 0) t1 = numOfWays(pos+1);

        if(pos+1 < n) {
            int v2 = v1 * 10 + (S[pos+1] - '0');

            if(v2 <= 26 and v1 > 0) t2 = numOfWays(pos+2);
        }

        return dp[pos] =  t1 + t2;
    }

};

