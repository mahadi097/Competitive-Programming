class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int ans = 0, n = prices.size();
        vector <int> dp(k*2+1);

//        dp[0] = 0;
        for(int i = 1; i < k*2+1; i++) dp[i] = -1e8;

        for(auto v: prices) {
            for(int i = k*2; i >= 1; i--) {
                if(i & 1) dp[i] = max(dp[i], dp[i-1]-v);
                else dp[i] = max(dp[i], dp[i-1]+v), ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};
