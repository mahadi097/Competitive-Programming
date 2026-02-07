class Solution {
public:
    vector<vector<int>> events, dp;
    int n, k;
    int maxValue(vector<vector<int>>& events, int k) {
        this->events = events;
        this->k = k;
        n = events.size();
        dp.resize(n, vector<int>(k, -1));

        sort(this->events.begin(), this->events.end());

        return solve(0, 0);        
    }

    int solve(int in, int c) {
        if(in == n or c == k) return 0;
        int &res = dp[in][c];
        if(res != -1) return res;

        int r1 = solve(in+1, c);

        int st = in+1, en = n-1, nextIn = n;
        while(st <= en) {
            int mid = (st + en) / 2;
            if(events[mid][0] > events[in][1]) nextIn = mid, en = mid - 1;
            else st = mid + 1;
        }
        int r2 = events[in][2] + solve(nextIn, c+1);

        return res = max(r1, r2);
    }
};