class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map <int, int> f;
        f[0] = 1;

        int sum = 0, ans = 0;
        for(auto v: nums) {
            if(v < 0) v = ((v % k) + k) % k;

            sum = (sum + v) % k;
            ans += f[sum];
            f[sum]++;
        }

        return ans;
    }
};