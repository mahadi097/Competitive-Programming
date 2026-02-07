class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map <int, int> f, f1, f2;
        
        for(int b: basket1) f[b]++, f1[b]++;
        for(int b: basket2) f[b]++, f2[b]++;

        for(auto p: f) if(p.second & 1) return -1;

        int mn = INT_MAX;
        vector <int> c1, c2;

        for(int b: basket1) {
            mn = min(mn, b);
            if(f1[b] <= f[b]/2) continue;
            c1.push_back(b);
            f1[b]--;
        } 
        for(int b: basket2) {
            mn = min(mn, b);
            if(f2[b] <= f[b]/2) continue;
            c2.push_back(b);
            f2[b]--;
        } 

        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());

        int m = c1.size();
        long long ans = 0;

        for(int i = 0, j = m-1; i < m and j >= 0; i++, j--) {
            ans += min(min(c1[i], c2[j]), min(mn, c2[j])+min(mn, c1[i]));
        }

        return ans;
    }
};