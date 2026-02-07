class Solution {
private:
    vector<int> dr9 = {0, -1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dc9 = {0, -1, 0, 1, -1, 1, -1, 0, 1};

    int getMax(int i1, int j1, vector<vector<int>>& grid) {
        int mx = 0;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                int r = i1 + dr9[i];
                int c = j1 + dc9[j];
                mx = max(mx, grid[r][c]);
            }
        }

        return mx;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2, vector<int>(n-2));

        for(int i = 0; i < n-2; i++) {
            for(int j = 0; j < n-2; j++) {
                maxLocal[i][j] = getMax(i+1, j+1, grid);
            }
        }

        return maxLocal;
    }
};