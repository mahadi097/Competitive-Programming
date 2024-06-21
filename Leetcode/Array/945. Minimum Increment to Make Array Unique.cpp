class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> f(2e5+1, 0);

        sort(nums.begin(), nums.end());

        for(auto v: nums) f[v]++;

        int ans = 0, st = 0;
        for(auto v: nums) {
            if(f[v] > 1) {
                f[v]--;
                st = max(st, v);
                while(f[st]) st++;
                f[st] = 1;
                ans += (st - v);
            }
        }

        return ans;
    }
};