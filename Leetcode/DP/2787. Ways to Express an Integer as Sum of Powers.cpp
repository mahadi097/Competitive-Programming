class Solution {
public:
    int numberOfWays(int n, int x) {
        vector <vector<int>> dp(n+1, vector<int>(n+1, -1));
        vector <int> powX;
        const int mod = 1e9 + 7;

        for(int i = 1; i <= n; i++) {
            int nn = 1;
            bool bad = false;
            for(int j = 1; j <= x; j++) {
                nn *= i;
                if(nn > n) { bad = true; break; }
            }
            powX.push_back(bad ? -1 : nn);
        }

        function<int(int, int)> solve = [&](int pos, int sum) -> int {
            if (pos == n) return sum == n;
            int &res = dp[pos][sum];
            if (res != -1) return res;

            res = solve(pos+1, sum);
            if (powX[pos] != -1 and sum+powX[pos] <= n) res += solve(pos+1, sum+powX[pos]);
            res %= mod;

            return res;
        };
        
        return solve(0, 0);
    }
};