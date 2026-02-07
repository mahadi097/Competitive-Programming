class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> cumCost(n);
        
        for(int i = 0; i < n; i++) {
            int costI = abs(s[i] - t[i]);
            cumCost[i] = (i == 0) ? costI : cumCost[i-1] + costI;
        }

        int mxLen = 0;
        for(int i = 0; i < n; i++) {
            int mxLenCur = 0, st = i, en = n-1;

            while(st <= en) {
                int mid = (st + en) / 2;
                int costT = (i == 0) ? cumCost[mid] : cumCost[mid] - cumCost[i-1];

                if(costT <= maxCost) mxLenCur = (mid - i + 1), st = mid + 1;
                else en = mid - 1;
            }

            mxLen = max(mxLen, mxLenCur);
        }

        return mxLen;
    }
};