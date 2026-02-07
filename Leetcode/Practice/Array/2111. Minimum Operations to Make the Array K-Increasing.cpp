class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0;

        for(int i = 0; i < k; i++) {
            vector <int> v;

            for(int j = i; j < arr.size(); j += k) v.push_back(arr[j]);

            ans += solve(v);
        }

        return ans;
    }

    int solve(vector <int> v) {
        int n = v.size(), lis = 0;

        vector <int> I(n+1, 1e9);
        I[0] = -1e9;

        for(int i = 0; i < n; i++) {
            int pos = upper_bound(I.begin(), I.end(), v[i]) - I.begin();
            I[pos] = v[i];
            lis = max(lis, pos);
        }

        return (n - lis);
    }
};
