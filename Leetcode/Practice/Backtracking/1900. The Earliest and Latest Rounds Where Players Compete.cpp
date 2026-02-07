class Solution {
private:
    int n, p1, p2;
    int mn = INT_MAX, mx = 0;

    bool isOne(int x, int pos) {
        return x & (1 << pos);
    }

    int setOne(int x, int pos) {
        return x | (1 << pos);
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        this->n = n-1, p1 = firstPlayer-1, p2 = secondPlayer-1;

        solve(0, this->n, 0, 1);
        return {mn, mx};
    }   

    void solve(int i, int j, int state, int round) {
        if(i >= j) solve(0, n, state, round+1);
        else if(isOne(state, i)) solve(i+1, j, state, round);
        else if(isOne(state, j)) solve(i, j-1, state, round);
        else if(i == p1 and j == p2) {
            mn = min(mn, round);
            mx = max(mx, round);
        }
        else if(i == p1 or i == p2) solve(i+1, j-1, setOne(state, j), round);
        else if(j == p1 or j == p2) solve(i+1, j-1, setOne(state, i), round);
        else {
            solve(i+1, j-1, setOne(state, i), round);
            solve(i+1, j-1, setOne(state, j), round);
        }
    }
};