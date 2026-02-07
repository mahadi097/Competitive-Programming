class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
      	int n = fruits.size(), rightSt = n, ans = 0;
        vector <int> preSum(n, 0);

        for(int i = 0; i < n; i++) {
            if(fruits[i][0] > startPos) { rightSt = i; break; }
        }

        for(int i = 0; i < n; i++) preSum[i] = (i == 0) ? fruits[i][1] : preSum[i-1] + fruits[i][1];

        for(int i = 0; i < n; i++) {
            int d = abs(startPos - fruits[i][0]);
            if(d > k) continue;

            int res, remD = k - d;

            if(i < rightSt) {
                res = preSum[rightSt-1];
                if(i != 0) res -= preSum[i-1];

                int st = rightSt, en = n-1, pos = -1;

                while(st <= en) {
                    int mid = (st + en) / 2;
                    if( ((fruits[mid][0] - startPos) * 2) <= remD) pos = mid, st = mid + 1;
                    else en = mid - 1;
                }

                if(pos != -1) res += (preSum[pos] - preSum[rightSt-1]);
            }
            else {
                res = preSum[i];
                if(rightSt != 0) res -= preSum[rightSt-1];

                int st = 0, en = rightSt-1, pos = -1;

                while(st <= en) {
                    int mid = (st + en) / 2;
                    if( ((startPos - fruits[mid][0]) * 2) <= remD) pos = mid, en = mid - 1;
                    else st = mid + 1;
                }

                if(pos != -1) {
                    res += preSum[rightSt-1];
                    if(pos != 0) res -= preSum[pos-1];
                }
            }

            ans = max(ans, res);
        }

        return ans;
    }
};


