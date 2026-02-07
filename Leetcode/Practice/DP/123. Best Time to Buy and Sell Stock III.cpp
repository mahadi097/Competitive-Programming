class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <int> dp(5, -1e8);

        dp[0] = 0;

        for(auto v: prices) {
            dp[4] = max(dp[4], dp[3]+v);
            dp[3] = max(dp[3], dp[2]-v);

            dp[2] = max(dp[2], dp[1]+v);
            dp[1] = max(dp[1], -v);
        }

        int ans = max({ dp[0], dp[2], dp[4] });

        return ans;
    }
};
