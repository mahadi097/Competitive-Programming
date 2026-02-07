class Solution {
private:
    int n;
    vector <vector<int>> dp;
    
    int solve(int i, int jLast, vector<vector<int>>& grid) {
        if(i == n) return 0;

        int &res = dp[i][jLast];
        if(res != INT_MAX) return res;

        for(int j = 0; j < n; j++) {
            if(j+1 == jLast) continue; // considering j & jLast both as 1-based index
            res = min(res, grid[i][j] + solve(i+1, j+1, grid)); 
        }

        return res;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n, vector<int>(n+1, INT_MAX));

        return solve(0, 0, grid); // considering column j as 1-based index to cover the base case of the first row (i = 0), so jLast = 0 means no column was selected before
    }
};