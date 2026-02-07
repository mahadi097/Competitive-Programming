class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int ans = n-1;

        if(restrictions.empty()) return ans;

        sort(restrictions.begin(), restrictions.end(), greater<vector<int>>());

        for(int i = 0; i < restrictions.size(); i++) {
            int pos = restrictions[i][0], mxH = restrictions[i][1];
            int dis = n - pos;

            if(i == 0) {
                ans = min(ans, mxH+dis);
                restrictions[i][1] = min(pos-1, mxH);
                continue;
            }

            int prvPos = restrictions[i-1][0], prvMxH = restrictions[i-1][1];
            int prvDis = prvPos - pos;

            if(mxH+prvDis >= prvMxH) {
                restrictions[i][1] = max(prvMxH-prvDis, 0);
            }
            else {
                restrictions[i][1] = mxH;
                ans = mxH + dis;
            }
        }

        return ans;
    }
};
