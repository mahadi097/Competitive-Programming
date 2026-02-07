class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<vector<int>> fL, fR;

        for(auto f: fruits) {
            if (f[0] <= startPos) fL.push_back(f);
            else fR.push_back(f);
        }

        int nL = fL.size(), nR = fR.size();
        vector<int> cumL(nL), cumR(nR);

        for(int i = 0; i < nL; i++) cumL[i] = i == 0 ? fL[i][1] : cumL[i-1] + fL[i][1];
        for(int i = 0; i < nR; i++) cumR[i] = i == 0 ? fR[i][1] : cumR[i-1] + fR[i][1];

        int ans = 0;

        for(int i = 0; i < nL; i++) {
            if(startPos-fL[i][0] > k) continue;

            int kk = k - (startPos-fL[i][0]);
            int c = cumL[nL-1]; 
            if (i > 0) c -= cumL[i-1];

            int maxPos = fL[i][0] + kk;

            int st = 0, en = nR-1, posR = -1;
            while(st <= en) {
                int mid = (st + en) / 2;
                if(fR[mid][0] <= maxPos) posR = mid, st = mid + 1;
                else en = mid - 1;
            }
            if (posR != -1) c += cumR[posR];

            ans = max(ans, c);
        }

        for(int i = 0; i < nR; i++) {
            if(fR[i][0]-startPos > k) continue;

            int kk = k - (fR[i][0] - startPos);
            int c = cumR[i];

            int minPos = fR[i][0] - kk;

            int st = 0, en = nL-1, posL = -1;
            while(st <= en) {
                int mid = (st + en) / 2;
                if(fL[mid][0] >= minPos) posL = mid, en = mid - 1;
                else st = mid + 1;
            }
            if(posL != -1) {
                c += cumL[nL-1];
                if(posL > 0) c -= cumL[posL-1];
            }
            
            ans = max(ans, c);
        }

        return ans;
    }
};