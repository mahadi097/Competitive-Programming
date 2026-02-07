class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = solve(height);

        reverse(height.begin(), height.end());

        ans = max(ans, solve(height));

        return ans;
    }

    int solve(vector <int> &v) {
        int n = v.size(), res = 0;
        vector <int> mx(n);

        for(int i = n-1; i >= 0; i--) mx[i] = (i == n-1) ? v[i] : max(mx[i+1], v[i]);

        for(int i = 0; i < n; i++) {
            int st = i+1, en = n-1, area = 0;

            while(st <= en) {
                int mid = (st + en) / 2;

                if(mx[mid] >= v[i]) {
                    area = v[i] * (mid - i);
                    st = mid + 1;
                }
                else en = mid - 1;
            }

            res = max(res, area);
        }

        return res;
    }
};
