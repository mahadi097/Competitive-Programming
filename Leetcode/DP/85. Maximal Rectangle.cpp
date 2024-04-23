class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int dp[205][205][205][2] = {0}, ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '0') continue;

                for(int k = j; k >= 0; k--) {
                    if(matrix[i][k] == '0') break;

                    dp[i][j][k][0] = (i-1 < 0) ? j-k+1 : dp[i-1][j][k][0] + j-k+1;
                    ans = max(ans, dp[i][j][k][0]);
                }

                for(int k = i; k >= 0; k--) {
                    if(matrix[k][j] == '0') break;

                    dp[i][j][k][1] = (j-1 < 0) ? i-k+1 : dp[i][j-1][k][1] + i-k+1;
                    ans = max(ans, dp[i][j][k][1]);
                }
            }
        }

        return ans;
    }
};

