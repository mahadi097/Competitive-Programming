class Solution {
public:
    int findLHS(vector<int>& nums) {
        map <int, int> f;
        for (auto v: nums) f[v]++;
        
        int ans = 0;
        for (auto p: f) {
            if(f.count(p.first+1)) ans = max(ans, p.second+f[p.first+1]);
        }

        return ans;
    }
};