class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 1, n = nums.size();
        vector<vector<int>> dp(k, vector<int>(n, 1));

        for(int j = 0; j < n; j++) {
            int y = nums[j] % k;
            for(int i = 0; i < j; i++) {
                int x = nums[i] % k;
                dp[x][j] = dp[y][i] + 1;
                ans = max(ans, dp[x][j]);
            }
        }

        return ans;
    }
};