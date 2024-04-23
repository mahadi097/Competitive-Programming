class Solution {
public:
    unordered_map <int, int> par, f;

    int Find(int x) {
        if(par[x] == x) return x;
        return par[x] = Find(par[x]);
    }

    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int ans = 1;

        for(auto v: nums) f[v] = 1, par[v] = v;

        for(auto v: nums) {
            if(!f[v-1]) continue;

            par[v] = Find(par[v-1]);
        }

        for(auto v: nums) {
            if(!f[v-1]) continue;

            par[v] = Find(par[v-1]);

            ans = max(ans, v-par[v]+1);
        }

        return ans;
    }
};


