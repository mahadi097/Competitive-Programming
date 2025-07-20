class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gapLeft(n), gapRight(n);

        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int gapNow = i-1 == -1 ? startTime[i] : startTime[i] - endTime[i-1];
            gapLeft[i] = gapNow;
            if(i > 0) gapLeft[i] = max(gapLeft[i-1], gapLeft[i]);
            ans = max(ans, gapNow);
        }

        for(int i = n-1; i >= 0; i--) {
            int gapNow = i+1 == n ? eventTime - endTime[i] : startTime[i+1] - endTime[i];
            gapRight[i] = gapNow;
            if(i < n-1) gapRight[i] = max(gapRight[i+1], gapRight[i]);
            ans = max(ans, gapNow);
        }

        for(int i = 0; i < n; i++) {
            int mxLeft = i == 0 ? 0 : gapLeft[i-1];
            int mxRight = i == n-1 ? 0 : gapRight[i+1];
            int t = endTime[i] - startTime[i];
            
            if(mxLeft >= t or mxRight >= t) {
                if(i == 0) ans = max(ans, startTime[1]);
                else if(i == n-1) ans = max(ans, eventTime-endTime[n-2]);
                else ans = max(ans, startTime[i+1]-endTime[i-1]);
            }

            if(i == 0) ans = max(ans, startTime[i]+startTime[i+1]-endTime[i]);
            else if(i == n-1) ans = max(ans, eventTime-endTime[i]+startTime[i]-endTime[i-1]);
            else ans = max(ans, startTime[i]-endTime[i-1]+startTime[i+1]-endTime[i]);
        }

        return ans;
    }
};