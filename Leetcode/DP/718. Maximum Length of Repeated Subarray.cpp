class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int ans = 0;
        vector <vector<int>> dp(n1, vector<int>(n2));

        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                if(nums1[i] != nums2[j]) continue;

                dp[i][j] = 1;
                if(i-1 >= 0 and j-1 >= 0) dp[i][j] += dp[i-1][j-1];

                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
