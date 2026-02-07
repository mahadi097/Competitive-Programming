class Solution {
public:
    vector <int> v;
    int n, dp[1005][1005][2][2];

    int minimumMountainRemovals(vector<int>& nums) {
        v = nums;
        n = v.size();
        memset(dp, -1, sizeof dp);

        int ans = 1e9;
        for(int i = 0; i < n; i++) ans = min(ans, i + solve(i+1, i, 0, 1));

        return ans;
    }

    int solve(int pos, int prvPos, bool f, bool st) {
        if(pos == n) return f ? 0: 1e9;
        int &res = dp[pos][prvPos][f][st];
        if(res != -1) return res;

        res = 1 + solve(pos+1, prvPos, f, st);

        if(!f) {
            if(v[pos] > v[prvPos]) res = min(res, solve(pos+1, pos, 0, 0));
            else if(v[pos] < v[prvPos] and !st) res = min(res, solve(pos+1, pos, 1, 0));
        }
        else if(f and v[pos] < v[prvPos]) res = min(res, solve(pos+1, pos, 1, 0));

        return res;
    }
};
