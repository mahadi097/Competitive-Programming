class Solution {
public:
    int n, dp[1005][2];

    int minimumMountainRemovals(vector<int>& nums) {
        n = nums.size();

        for(int i = 0; i < 1005; i++) for(int j = 0; j < 2; j++) dp[i][j] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] >= nums[i]) continue;

                dp[i][0] = max(dp[i][0], 1 + dp[j][0]);
            }
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j > i; j--) {
                if(nums[j] >= nums[i]) continue;

                dp[i][1] = max(dp[i][1], 1 + dp[j][1]);
            }
        }

        int ans = 1e9;
        for(int i = 0; i < n; i++) {
            if(dp[i][0] == 1 or dp[i][1] == 1) continue;

            int c = dp[i][0] + dp[i][1] - 1;
            ans = min(ans, n-c);
        }

        return ans;
    }
};
