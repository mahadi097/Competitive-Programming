class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> cost;
        
        for(int i = 0; i < n; i++) cost.push_back(abs(s[i] - t[i]));

        int mxLen = 0, costCur = 0;
        for(int i = 0, j = -1; i < n; i++) {
            if(i > j) j = i, costCur = 0;
            else costCur -= cost[i-1];

            while(j < n and costCur+cost[j] <= maxCost) {
                costCur += cost[j];
                j++;
            }

            mxLen = max(mxLen, j - i);
        }

        return mxLen;
    }
};