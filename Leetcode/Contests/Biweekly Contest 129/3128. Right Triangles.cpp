class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans = 0;
        int r = grid.size(), c = grid[0].size();
        
        vector<int> row(r, 0), col(c, 0);
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1) row[i]++, col[j]++;
            }
        }
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1) {
                    long long t = (row[i] - 1) * (col[j] - 1);
                    ans += t;
                }
            }
        }
        
        return ans;
    }
};