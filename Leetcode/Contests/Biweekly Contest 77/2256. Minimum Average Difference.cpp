class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int index = 0, mn = 1e9;

        int n = nums.size();
        vector <long long> cum(n), ad(n);

        for(int i = 0; i < n; i++) {
            cum[i] = (i == 0) ? nums[i] : nums[i] + cum[i-1];
        }

        for(int i = 0; i < n; i++) {
            long long x = cum[i] / (i+1);

            long long y = 0;
            if(i != n-1) y = (cum[n-1] - cum[i]) / (n-i-1);

            ad[i] = abs(x - y);

            if(ad[i] < mn) mn = ad[i], index = i;
        }

        return index;
    }
};