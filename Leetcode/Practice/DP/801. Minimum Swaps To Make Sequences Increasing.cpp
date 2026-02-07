class Solution {
public:
    int n;
    vector <vector<int>> a;
    int dp[100005][2];

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        memset(dp, -1, sizeof dp);

        for(int i = 0; i < n; i++) {
            vector <int> tmp;
            tmp.push_back(nums1[i]);
            tmp.push_back(nums2[i]);

            a.push_back(tmp);
        }

        return solve(0, 0);
    }

    int solve(int pos, int f) {
        if(pos == n) return 0;
        int &res = dp[pos][f];
        if(res != -1) return res;

        if(pos == 0) res = min( solve(pos+1, 0), 1 + solve(pos+1, 1) );
        else {
            int t1 = 1e6, t2 = 1e6;

            int p = f ? 1 : 0;

            if(a[pos][0] > a[pos-1][p] and a[pos][1] > a[pos-1][p^1]) t1 = solve(pos+1, 0);
            if(a[pos][1] > a[pos-1][p] and a[pos][0] > a[pos-1][p^1]) t2 = 1 + solve(pos+1, 1);

            res = min(t1, t2);
        }

        return res;
    }
};


