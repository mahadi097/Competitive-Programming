class Solution {
private:
    const int mod = 1e9 + 7;
    int dp[100002][3][3][2];
    // vector<vector<vector<vector<int>>>> dp{100002, vector<vector<vector<int>>>(3, vector<vector<int>>(3, vector<int>(2, -1)))}; // this vector gives me TLE

    // st = 0 for absent, 1 for late, 2 for present
    // con = number of consecutive days of the same state
    int solve(int day, int st, int con, int ab, int n) { 
        if(day == n) return 1;
        int &res = dp[day][st][con][ab];
        if(res != -1) return res;

        int r3(0), r2(0), r1 = solve(day+1, 2, 0, ab, n) % mod;
        if(!ab) r2 = solve(day+1, 0, 0, 1, n) % mod;
        if(st != 1 or (st == 1 and con < 2)) r3 = solve(day+1, 1, con+1, ab, n) % mod;

        return res = ((long long) r1 + r2 + r3) % mod;
    }

public:
    int checkRecord(int n) {
        memset(dp, -1, sizeof dp);
        return solve(0, 2, 0, 0, n);
    }
};