class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i = 0; i <= 1; i++) {
            for(int j = 0; j <= 1; j++) {
                int c = solve(i, j, grid);
                if(c >= 3) return true;
            }
        }

        return false;
    }

    int solve(int i, int j, vector<vector<char>>& grid) {
        int w = (grid[i][j] == 'W') + (grid[i][j+1] == 'W') + (grid[i+1][j] == 'W') + (grid[i+1][j+1] == 'W');
        int b = (grid[i][j] == 'B') + (grid[i][j+1] == 'B') + (grid[i+1][j] == 'B') + (grid[i+1][j+1] == 'B');
        return max(w, b);
    }
};