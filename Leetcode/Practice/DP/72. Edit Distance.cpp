class Solution {
public:
    int n1, n2, dp[505][505];
    string s1, s2;

    int minDistance(string word1, string word2) {
        s1 = word1, s2 = word2;
        n1 = word1.size(), n2 = word2.size();

        memset(dp, -1, sizeof dp);

        return solve(0, 0);
    }

    int solve(int p1, int p2) {
        if(p1 == n1) return (n2 - p2);
        if(p2 == n2) return (n1 - p1);
        int &res = dp[p1][p2];
        if(res != -1) return res;

        if(s1[p1] == s2[p2]) res = solve(p1+1, p2+1);
        else {
            res = 1 + solve(p1, p2+1);
            res = min(res, 1 + solve(p1+1, p2));
            res = min(res, 1 + solve(p1+1, p2+1));

//            res = min(res, 1 + solve(p1+1, p2));
//            res = min(res, 1 + solve(p1, p2+1));
//            res = min(res, 1 + solve(p1+1, p2+1));
        }

        return res;
    }
};
