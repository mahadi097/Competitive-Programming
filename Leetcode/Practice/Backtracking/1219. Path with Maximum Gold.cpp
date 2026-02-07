class Solution {
private:
    int m, n;
    vector<vector<int>> vis;

    int isValid(int i, int j, vector<vector<int>>& grid) {
        return i >= 0 and i < m and j >= 0 and j < n and grid[i][j] and !vis[i][j]; 
    }

    int solve(int i, int j, vector<vector<int>>& grid) {
        int res = 0;
        vis[i][j] = 1;

        if(isValid(i, j-1, grid)) res = max(res, solve(i, j-1, grid));
        if(isValid(i-1, j, grid)) res = max(res, solve(i-1, j, grid));
        if(isValid(i, j+1, grid)) res = max(res, solve(i, j+1, grid));
        if(isValid(i+1, j, grid)) res = max(res, solve(i+1, j, grid));

        vis[i][j] = 0;

        return grid[i][j] + res;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vis.resize(m, vector<int>(n));

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    ans = max(ans, solve(i, j, grid));
                }
            }
        }

        return ans;
    }
};