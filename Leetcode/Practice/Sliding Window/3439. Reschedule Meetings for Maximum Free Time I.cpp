class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> cum(n, 0);

        for(int i = 0; i < n; i++) {
            cum[i] = (endTime[i] - startTime[i]);
            if (i > 0) cum[i] += cum[i-1];
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int endT = i-k < 0 ? cum[i] : endTime[i-k] + (cum[i] - cum[i-k]);
            ans = max(ans, i+1 < n ? startTime[i+1]-endT : eventTime-endT);
        }

        return ans;
    }
};