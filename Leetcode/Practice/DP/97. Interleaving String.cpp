class Solution {
public:
    int dp[202][102][2] = {0};

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

        if(n1+n2 != n3) return 0;

        dp[0][0][0] = dp[0][0][1] = 1;

        for(int i = 1; i <= n3; i++) {
            for(int k = 0; k <= 1; k++) {

                if(k == 0) {
                    for(int j = 1; j <= min(i, n1); j++) {
                        if(s1[j-1] != s3[i-1] or dp[i][j][k]) continue;

                        dp[i][j][k] = dp[i-1][j-1][k] and dp[i-1][i-j][k^1];

                        if(dp[i][j][k]) dp[i][i-j][k^1] = 1;
                    }
                }
                else {
                    for(int j = 1; j <= min(i, n2); j++) {
                        if(s2[j-1] != s3[i-1] or dp[i][j][k]) continue;

                        dp[i][j][k] = dp[i-1][j-1][k] and dp[i-1][i-j][k^1];

                        if(dp[i][j][k]) dp[i][i-j][k^1] = 1;
                    }
                }
            }
        }

        return dp[n3][n1][0] == 1 or dp[n3][n2][1] == 1;
    }
};
