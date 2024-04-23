class Solution {
public:
    map <pair<int,int>, bool> dp;
    bool f[2005];
    string S, P;

    bool isMatch(string s, string p) {
        S = s, P = p;

        for(int i = (int) P.size()-1; i >= 0; i--) {
            if(P[i] != '*') break;
            f[i] = 1;
        }

        return solve(0, 0);
    }

    bool solve(int p1, int p2) {
        if(p1 == S.size()) return p2 == P.size() or f[p2];
        if(p2 == P.size()) return p1 == S.size();

        if(dp.find({p1, p2}) != dp.end()) return dp[{p1, p2}];
        bool &res = dp[{p1, p2}];

        res = 0;

        if(P[p2] == '?' or P[p2] == '*' or S[p1] == P[p2]) res = solve(p1+1, p2+1);
        if(P[p2] == '*') {
            res |= solve(p1+1, p2);
            res |= solve(p1, p2+1);
        }

        return res;
    }
};
