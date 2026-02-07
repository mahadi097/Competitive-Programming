class Solution {
private: 
    void toggleRow(int i, vector<vector<int>>& grid) {
        int n = grid[0].size();
        for(int j = 0; j < n; j++) grid[i][j] ^= 1;
    }

    void toggleColumn(int j, vector<vector<int>>& grid) {
        int m = grid.size();
        for(int i = 0; i < m; i++) grid[i][j] ^= 1;
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) toggleRow(i, grid);
        }

        for(int j = 1; j < n; j++) {
            int cOne = 0;
            for(int i = 0; i < m; i++) {
                if(grid[i][j] == 1) cOne++;
            }

            int cZero = m - cOne;
            if(cOne < cZero) toggleColumn(j, grid);
        }

        int score = 0;
        for(int i = 0; i < m; i++) {
            int num = 0;
            for(int j = 0, k = n-1; j < n; j++, k--) {
                if(grid[i][j] == 1) num += (1<<k);
            }

            score += num;
        }

        return score;
    }
};